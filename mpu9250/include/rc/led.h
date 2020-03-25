/**
 * <rc/led.h>
 *
 * @brief      Control the LEDs on Robotics Cape and BeagleBone Blue.
 *
 * @author     James Strawson
 * @date       1/31/2018
 *
 * @addtogroup LED
 * @{
 */

#ifndef RC_LED_H
#define RC_LED_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum rc_led_t{
	RC_LED_GREEN,
	RC_LED_RED,
	RC_LED_USR0,
	RC_LED_USR1,
	RC_LED_USR2,
	RC_LED_USR3,
	RC_LED_BAT25,
	RC_LED_BAT50,
	RC_LED_BAT75,
	RC_LED_BAT100,
	RC_LED_WIFI
} rc_led_t;

/**
 * @brief      sets the state of an LED
 *
 * @param[in]  led    rc_led_t enum
 * @param[in]  value  0 for OFF, non-zero for ON
 *
 * @return     0 on success, -1 on failure
 */
int rc_led_set(rc_led_t led, int value);


void rc_led_cleanup();

/**
 * @brief      gets the current state of an LED
 *
 * @param[in]  led   rc_led_t enum
 *
 * @return     0 if off, 1 if on, -1 on error
 */
int rc_led_get(rc_led_t led);

/**
 * @brief      blinks an led at specified frequency and duration.
 *
 *             This is a blocking function call, it does not return until either
 *             the specified duration has completed or rc_led_stop_blink has
 *             been called from another thread.
 *
 * @param[in]  led       rc_led_t enum
 * @param[in]  hz        blink frequency in HZ
 * @param[in]  duration  blink duration in seconds
 *
 * @return     0 on success, -1 on error, 1 if function exited prematurely.
 */
int rc_led_blink(rc_led_t led, float hz, float duration);

/**
 * @brief      Stops an LED from blinking.
 *
 *             Since rc_led_blink is a blocking function, it's obviously
 *             necessary to call rc_led_stop_blink from a separate thread or
 *             signal handler. This will cause rc_led_blink to return 1 if
 *             blinking was stopped mid-way. Also see
 *             rc_led_stop_blink_all
 *
 * @param[in]  led   rc_led_t enum
 */
void rc_led_stop_blink(rc_led_t led);

/**
 * @brief      stops all LEDs from blinking
 *
 *             Since rc_led_blink is a blocking function, it's obviously
 *             necessary to call rc_led_stop_blink from a separate thread or
 *             signal handler. This will cause rc_led_blink to return 1 if
 *             blinking was stopped mid-way.
 */
void rc_led_stop_blink_all();

#ifdef __cplusplus
}
#endif

#endif // RC_LED_H

/** @}  end group LED */