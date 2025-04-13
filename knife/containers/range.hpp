#pragma once

namespace knife::containers {
    template<typename T>
    class range {
        protected:
            T* data;
        public:
            virtual T* begin() = 0;
            virtual T* end() = 0;
            virtual ~range() = default;
    };
} //knife::container