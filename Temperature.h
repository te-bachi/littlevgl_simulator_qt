
#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

namespace dermair {
    class Temperature
    {
        public:
            enum Type {
                VALID,
                INVALID
            };

        private:
            Type            m_type;
            float           m_value;

        public:
                            Temperature();
                            Temperature(Type type, float value);
            virtual         ~Temperature();

            bool            isValid();
            void            validate();

            float           getValue();
            void            setValue(float value);
    };
};

#endif
