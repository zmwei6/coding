/**
 * <rc/motor.h>
 *
 * @brief      Control 4 DC motor Channels
 *
 *             The robotics cape can drive 4 DC motors bidirectionally powered
 *             only from a 2-cell lithium battery pack connected to the cape.
 *             The motors will not draw power from USB or the 9-18v DC Jack.
 *             Each channel can support 1.2A continuous and the user must be
 *             careful to choose motors which will not exceed this rating when
 *             stalled. Each channel is broken out on an independent 2-pin JST
 *             ZH connector.
 *
 * @author     James Strawson
 * @date       1/31/2018
 *
 * @addtogroup Motor
 * @{
 */

#ifndef RC_MOTOR_H
#define RC_MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief      Initializes all 4 motors and leaves them in a free-spin (0
 *             throttle) state.
 *
 *             Note, if the user is optionally using the rc_motor_standby
 *             functionality they should be aware that rc_motor_init starts
 *             standby mode in a disabled state so it is not necessary for the majority of users who are not interested in standby mode to
 *
 * @return     0 on success, -1 on failure which is usually due to lack of user
 *             permissions to access the gpio and pwm systems.
 */
int rc_motor_init();

/**
 * @brief      Puts all 4 motors into a free-spin (0 throttle) state, puts the
 *             h-bridges into standby mode, and closes all file pointers to GPIO
 *             and PWM systems.
 *
 * @return     0 on success, -1 on failure.
 */
int rc_motor_cleanup();

/**
 * @brief      Toggle the H-bridges in and out of low-power standby mode.
 *
 *             This is an entirely optional function as calling rc_motor_cleanup
 *             when your program closes will put the h-bridges into standby mode
 *             and then calling rc_motor_init at the beginning of your program
 *             will take them out of standby mode. However, if the user wishes
 *             to toggle in and out of standby mode in their program (for
 *             example while paused) then they can use this function.
 *
 * @param[in]  standby_en  1 to enable standby mode, 0 to disable
 *
 * @return     0 on success, -1 on failure.
 */
int rc_motor_standby(int standby_en);

/**
 * @brief      Sets the bidirectional duty cycle (power) to a single motor.
 *
 * @param[in]  motor  The motor channel (1-4)
 * @param[in]  duty   Duty cycle, -1.0 for full reverse, 1.0 for full forward
 *
 * @return     0 on success, -1 on failure
 */
int rc_motor_set(int motor, float duty);

/**
 * @brief      Sets the bidirectional duty cycle (power) to all motors.
 *
 * @param[in]  duty  Duty cycle, -1.0 for full reverse, 1.0 for full forward
 *
 * @return     0 on success, -1 on failure
 */
int rc_motor_set_all(float duty);

/**
 * @brief      Puts a motor into a zero-throttle state allowing it to spin
 *             freely.
 *
 *             This is accomplishes by putting both motor terminals connected to
 *             the h-bridge into a high-impedance state.
 *
 * @param[in]  motor  The motor channel (1-4)
 *
 * @return     0 on success, -1 on failure
 */
int rc_motor_free_spin(int motor);

/**
 * @brief      Puts all motors into a zero-throttle state allowing them to spin
 *             freely.
 *
 *             This is accomplishes by putting both motor terminals connected to
 *             the h-bridge into a high-impedance state.
 *
 * @return     0 on success, -1 on failure
 */
int rc_motor_free_spin_all();

/**
 * @brief      Connects the motor terminal pairs together which makes the motor
 *             fight against its own back EMF turning it into a brake resisting
 *             rotation.
 *
 * @param[in]  motor  The motor channel (1-4)
 *
 * @return     0 on success, -1 on failure
 */
int rc_motor_brake(int motor);

/**
 * @brief      Connects the motor terminal pairs together which makes the motor
 *             fight against its own back EMF turning it into a brake resisting
 *             rotation.
 *
 * @return     0 on success, -1 on failure
 */
int rc_motor_brake_all();


#ifdef __cplusplus
}
#endif

#endif // RC_MOTOR_H

/** @}  end group Motor */