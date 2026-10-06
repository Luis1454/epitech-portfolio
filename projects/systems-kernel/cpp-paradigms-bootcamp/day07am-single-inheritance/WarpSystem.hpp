/*
** EPITECH PROJECT, 2024
** WarpSystem.hpp
** File description:
** day 07 AM
*/

#ifndef _WARPSYSTEM_HPP_
#define _WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
            QuantumReactor() {_stability = true;}

            bool isStable() {return _stability;}

            void setStability(bool stability) {_stability = stability;}

            ~QuantumReactor(){};

        private:
            bool _stability;
    };
    class Core {
        public:
            Core(QuantumReactor *coreReactor) {_coreReactor = coreReactor;}

            QuantumReactor *checkReactor() {return _coreReactor;}

            ~Core(){};

        private:
            QuantumReactor *_coreReactor;
    };
}

#endif /* !_WARPSYSTEM_HPP_ */
