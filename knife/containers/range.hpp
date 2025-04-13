#pragma once

namespace knife::containers {
    template<typename T>
    class range {
        protected:
            T* data;
        public:
            virtual T* begin() const = 0;
            virtual T* end() const = 0;
            virtual ~range() = default;
    };
} //knife::container