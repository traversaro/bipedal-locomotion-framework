/**
 * @file traits.h
 * @authors Giulio Romualdi
 * @copyright 2020 Istituto Italiano di Tecnologia (IIT). This software may be modified and
 * distributed under the terms of the GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef BIPEDAL_LOCOMOTION_CONTINUOUS_DYNAMICAL_SYSTEM_IMPL_TRAITS_H
#define BIPEDAL_LOCOMOTION_CONTINUOUS_DYNAMICAL_SYSTEM_IMPL_TRAITS_H

#include <tuple>

#define BLF_CONTINUOUS_DYNAMICAL_SYSTEM_STATE(...) using State = std::tuple<__VA_ARGS__>

#define BLF_CONTINUOUS_DYNAMICAL_SYSTEM_STATE_DERIVATIVE(...) \
    using StateDerivative = std::tuple<__VA_ARGS__>

#define BLF_CONTINUOUS_DYNAMICAL_SYSTEM_STATE_INPUT(...) using Input = std::tuple<__VA_ARGS__>

/**
 * The user must call this macro before defining a ContinuousDynamicalSystem::DynamicalSystem
 * @param DynamicalSystemType the type of the dynamical system
 * @param StateType the list of the types used to define the state. The list must be defined using
 * round parenthesis. E.g. `(Eigen::VectorXd, Eigen::VectorXd)`.
 * @param StateDerivativeType the list of the types used to define the state derivative. The list
 * must be defined using round parenthesis. E.g. `(Eigen::VectorXd, Eigen::VectorXd)`.
 * @param InputType the list of the types used to define inputs. The list must be defined using
 * round parenthesis. E.g. `(Eigen::VectorXd, Eigen::VectorXd)`.
 */
#define BLF_DEFINE_CONTINUOUS_DYNAMICAL_SYSTEM_INTERAL_STRUCTURE(DynamicalSystemType, \
                                                                 StateType,           \
                                                                 StateDerivativeType, \
                                                                 InputType)           \
    namespace BipedalLocomotion                                                       \
    {                                                                                 \
    namespace ContinuousDynamicalSystem                                               \
    {                                                                                 \
    namespace internal                                                                \
    {                                                                                 \
    template <> struct traits<DynamicalSystemType>                                    \
    {                                                                                 \
        BLF_CONTINUOUS_DYNAMICAL_SYSTEM_STATE StateType;                              \
        BLF_CONTINUOUS_DYNAMICAL_SYSTEM_STATE_DERIVATIVE StateDerivativeType;         \
        BLF_CONTINUOUS_DYNAMICAL_SYSTEM_STATE_INPUT InputType;                        \
    };                                                                                \
    }                                                                                 \
    }                                                                                 \
    }

namespace BipedalLocomotion
{
namespace ContinuousDynamicalSystem
{
namespace internal
{

template <typename T> struct traits;

/// @note the following is from the Eigen library
/// here we say once and for all that traits<const T> == traits<T>
///
/// When constness must affect traits, it has to be constness on
/// template parameters on which T itself depends.
/// For example, traits<Map<const T> > != traits<Map<T> >, but
///              traits<const Map<T> > == traits<Map<T> >
template <typename T> struct traits<const T> : traits<T>
{
};

} // namespace internal
} // namespace ContinuousDynamicalSystem
} // namespace BipedalLocomotion

#endif // BIPEDAL_LOCOMOTION_CONTINUOUS_DYNAMICAL_SYSTEM_IMPL_TRAITS_H
