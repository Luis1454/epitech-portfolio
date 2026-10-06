/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Sparse
*/


#include "Sparse.hpp"
#include "Components/Component.hpp"
#include "Systems/System.hpp"
#include "Entities/Entity.hpp"
#include "Components/Position.hpp"

template class SparseArray<Entity>;
template class SparseArray<Component>;
template class SparseArray<System>;

template class SparseArray<bool>;
template class SparseArray<int>;
template class SparseArray<float>;
template class SparseArray<double>;

template class SparseArray<Position>;
