#include <Arduino.h>
#include <MFRC522.h>

#include "Mesonix.h"

using namespace Qybercom::Mesonix;

void Mesonix::_init (unsigned short pinSS, unsigned short pinReset) {
	this->_pinSS = pinSS;
	this->_pinReset = pinReset;
	this->_debounceUUID = 0; // use 2-5
	this->_debounceUUIDCount = 0;
	this->_uuid = "";
	this->_uuidChanged = false;
	this->_expectInserted = true;
	this->_expectEjected = false;
}

Mesonix::Mesonix (unsigned short pinSS) {
	this->_init(pinSS, 0);
}

Mesonix::Mesonix (unsigned short pinSS, unsigned short pinReset) {
	this->_init(pinSS, pinReset);
}

void Mesonix::InitMFRC () {
	this->_readerMFRC = new MFRC522();
	this->_readerMFRC->PCD_Init(this->_pinSS, this->_pinReset);

	pinMode(this->_pinSS, OUTPUT);
	digitalWrite(this->_pinSS, HIGH);
}

void Mesonix::UUIDReadDebounce (unsigned short count) {
	this->_debounceUUID = count;
}

unsigned short Mesonix::UUIDReadDebounce () {
	return this->_debounceUUID;
}

String Mesonix::UUID () {
	return this->_uuid;
}

String Mesonix::UUIDActual () {
	return this->_uuidActual;
}

bool Mesonix::UUIDChanged () {
	bool out = this->_uuidChanged;
	this->_uuidChanged = false;

	return out;
}

void Mesonix::Pipe () {
	this->_readerMFRC->PCD_Init();

	String value = "";
	bool card = this->_readerMFRC->PICC_IsNewCardPresent();

	if (card && this->_readerMFRC->PICC_ReadCardSerial()) {
		int i = 0;

		while (i < this->_readerMFRC->uid.size) {
			value += String(this->_readerMFRC->uid.uidByte[i], HEX);

			i++;
		}
	}

	this->_uuidActual = value;

	bool valueChanged = this->_uuid != value;
	if (this->_expectInserted) {
		if (value == "") this->_debounceUUIDCount = 0;
		else this->_debounceUUIDCount++;
	}

	if (this->_expectEjected) {
		if (value != "" && !valueChanged) this->_debounceUUIDCount = 0;
		else this->_debounceUUIDCount++;
	}

	if (valueChanged) {
		if (this->_debounceUUIDCount >= this->_debounceUUID) {
			this->_uuid = value;
			this->_uuidChanged = true;
			this->_debounceUUIDCount = this->_debounceUUID;

			if (value == "") {
				this->_expectInserted = true;
				this->_expectEjected = false;
			}
			else {
				this->_expectInserted = false;
				this->_expectEjected = true;
			}
		}
	}
}