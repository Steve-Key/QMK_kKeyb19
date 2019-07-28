
#include "kKeyb.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
//		writePinLow(D5);
//		DDRD &= ~(1<<5); //NumLock invertirovan, chtoby ne gorelo zrq
//        PORTD &= ~(1<<5);
	} else {
//		writePinHigh(D5);
//		DDRD |= (1<<5); //Pokazyvaet NumLock, tam cyfry
//        PORTD &= ~(1<<5);
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
//		writePinLow(B0);
//        DDRB |= (1<<0); //pokazyvaet CAPSLOCK, u menq eto russkie bukvy
//        PORTB &= ~(1<<0);
	} else {
//		writePinHigh(B0);
//        DDRB &= ~(1<<0);
//        PORTB &= ~(1<<0);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_KANA)) {
	} else {
	}


	led_set_user(usb_led);
}
