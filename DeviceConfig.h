#pragma once
// ==============================================================================================================
// === LOCAL DEFINITION =========================================================================================
// ==============================================================================================================
#define     HARD1   0x4F       //hardware type (0x4F41 - OA)
#define     HARD2   0x41       //hardware type
#define     HVERS   .01        //hardware version (OA 1)

#define     BVER    .01        //bootloader software major version
#define     BREV    .00        //bootloader software minor version
// ==============================================================================================================
// === NODE SERIAL NUMBER =======================================================================================
// ==============================================================================================================
#define     ID0     0x00            //node serial number MSB
#define     ID1     0x00            //node serial number
#define     ID2     0x00            //node serial number
#define     ID3     0x01            //node serial number LSB
// ==============================================================================================================
// === HARDWARE ID ==============================================================================================
// ==============================================================================================================
const byte HARDID[] PROGMEM = { HARD1, HARD2, HVERS, 0xFF, ID0, ID1, ID2, ID3 };

namespace Onixarts
{
	namespace HomeAutomationCore
	{
		namespace Hapcan
		{
			namespace Config
			{
				const byte RxFifoQueueSize = 10;				// max 255

				const byte InitialGroup = 3;					// Initial group identifier
				const byte InitialNode = 3;						// Initial node identifier

				namespace MCP
				{
					const byte InterruptPin = 2;				// CAN module interrupt is connected to this pin (see https://www.arduino.cc/en/Reference/AttachInterrupt)
					const byte CSPin = 10;						// SPI CS pin
					const byte OscillatorFrequency = MCP_8MHz;	// MCP oscillator frequency on MCP CAN module (or MCP_16MHz)
				}
			}

			namespace Message
			{
				//const byte SystemMessage0x00Flag = 0x00;
				const byte SystemMessage0x10Flag = 0x10;
				const byte SystemMessage0x11Flag = 0x11;
				const byte NormalMessage0x30Flag = 0x30;

				namespace System0x0F
				{
					// Handled by bootloader in programming mode
					const byte ExitAllFromBootloaderProgrammingMode = 0x10;
					const byte ExitOneNodeFromBootloaderProgrammingMode = 0x20;
					const byte AddressFrame = 0x30;
					const byte DataFrame = 0x40;
				}

				namespace System0x10
				{
					// Handled by bootloader
					const byte EnterProgrammingMode = 0x00;
					const byte RebootRequestToGroup = 0x10;
					const byte RebootRequestToNode = 0x20;
					const byte HardwareTypeRequestToGroup = 0x30;
					const byte HardwareTypeRequestToNode = 0x40;
					const byte FirmwareTypeRequestToGroup = 0x50;
					const byte FirmwareTypeRequestToNode = 0x60;
					const byte SetDefaultNodeAndGroupRequestToNode = 0x70;

					// Handled by functional firmware
					const byte StatusRequestToGroup = 0x80;
					const byte StatusRequestToNode = 0x90;
					const byte ControlMessage = 0xA0;

					//Handled by bootloader
					const byte SupplyVoltageRequestToGroup = 0xB0;
					const byte SupplyVoltageRequestToNode = 0xC0;
					const byte DescriptionRequestToGroup = 0xD0;
					const byte DescriptionRequestToNode = 0xE0;
					const byte DeviceIDRequestToGroup = 0xF0;
				}

				namespace System0x11
				{
					// Handled by functional firmware
					const byte DeviceIDRequestToNode = 0x10;
					const byte UptimeRequestToGroup = 0x20;
					const byte UptimeRequestToNode = 0x30;
					const byte HealthCheckRequestToGroup = 0x40;
					const byte HealthCheckRequestToNode = 0x50;
				}

				namespace Normal0x30
				{
					// Handled by functional firmware
					const byte ButtonNodeMessage = 0x10;
					const byte RelayMessage = 0x20;
					const byte InfraredReceiverMessage = 0x30;
					const byte TemperatureSensorMessage = 0x40;
					const byte InfraredTransmitterMessage = 0x50;
					const byte DimmerMessage = 0x60;
					const byte BlindControllerMessage = 0x70;
					const byte LedControllerMessage = 0x80;
				}
			}
		}
	}
}