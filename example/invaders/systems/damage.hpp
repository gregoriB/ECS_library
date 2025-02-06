#pragma once

#include "../components.hpp"
#include "../core.hpp"

namespace Systems::Damage
{
inline void cleanup(ECM &ecm)
{
}

inline auto update(ECM &ecm)
{
    ecm.getAll<DamageEvent>().each([&](EId eId, auto &damageEvents) {
        damageEvents.inspect([&](const DamageEvent &damageEvent) {
            auto &damageComps = ecm.get<DamageComponent>(damageEvent.dealerId);
            if (!damageComps)
                return;

            auto &amount = damageComps.peek(&DamageComponent::amount);
            ecm.add<HealthEvent>(eId, -1 * amount);
        });
    });

    return cleanup;
};
}; // namespace Systems::Damage
