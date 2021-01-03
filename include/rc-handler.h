#pragma once

namespace rc {

class RC_Handler {
    public:
        enum STEERING_DIRECTION {
            LEFT  = 0,
            RIGHT = 1
        };

        enum MOTOR_DIRECTION {
            FORWARD = 0,
            REVERSE = 1
        };

    public:
        /**
         * \brief get singleton instance of RC handler object
         */
        static RC_Handler& Instance();

        /**
         * \brief constructor for RC handler will reset GPIO pinouts
         */
        RC_Handler();

        /**
         * \brief setup pinouts
         */
        void setup();

        /**
         * \brief reset RC handler values to default
         */
        void reset();

        /**
         * \brief set steering value
         * 
         * \param value percentage value for steering (0.0 = 0%; 1.0 = 100%)
         *              Negative value = LEFT direction
         *              Positive value = RIGHT direction
         *              Zero value     = set steering to normal position
         */
        void setSteering(float value = 0.0f);

        /**
         * \brief set motor speed
         * 
         * \param value motor speed in percentage value (0.0 = 0%; 1.0 = 100%)
         *              Negative value = Reverse speed
         *              Positive value = Forward speed
         *              Zero value     = stop motor
         */
        void setMotorSpeed(float value = 0.0f);

        /**
         * \brief set RC car steer to LEFT
         */
        inline void left(float value = 1.0f) { setSteering(-value); }

        /**
         * \brief set RC car steer to RIGHT
         */
        inline void right(float value = 1.0f) { setSteering(value); }

        /**
         * \brief set RC car FORWARD speed
         */
        inline void forward(float value = 1.0f) { setMotorSpeed(value); }

        /**
         * \brief set RC car REVERSE speed
         */
        inline void reverse(float value = 1.0f) { setMotorSpeed(-value); }

        /**
         * \brief stop RC car
         */
        inline void stop() { setMotorSpeed(0.0f); }
};

};
