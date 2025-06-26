#pragma once

#include <Arduino.h>
#include <MFRC522.h>

namespace Qybercom {
	namespace Mesonix {
		class Mesonix {
			private:
				MFRC522* _readerMFRC;
				unsigned short _pinSS;
				unsigned short _pinReset;
				unsigned short _debounceUUID;
				unsigned short _debounceUUIDCount;
				String _uuid;
				String _uuidActual;
				bool _uuidChanged;
				bool _expectInserted;
				bool _expectEjected;

				void _init(unsigned short pinSS, unsigned short pinReset);

			public:
				Mesonix(unsigned short pinSS);
				Mesonix(unsigned short pinSS, unsigned short pinReset);

				void UUIDReadDebounce(unsigned short count);
				unsigned short UUIDReadDebounce();

				String UUID();
				String UUIDActual();
				bool UUIDChanged();

				void InitMFRC();

				void Pipe();
		};
	}
}