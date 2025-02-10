#pragma once

#include "../components.hpp"
#include "../core.hpp"

namespace Systems::Death
{
inline void cleanup(ECM &ecm)
{
    auto &deadIds = ecm.getEntityIds<DeathComponent>();
    for (const auto &id : deadIds)
        ecm.remove(id);
}

inline auto update(ECM &ecm)
{
    auto [deathSet] = ecm.getAll<DeathEvent>();
    deathSet.each([&](EId eId, auto &deathEvents) {
        auto [playerId, _] = ecm.getUnique<PlayerComponent>();
        if (eId == playerId)
        {
            ecm.add<PlayerEvent>(eId, PlayerEvents::DEATH);
            return;
        }

        auto [startTriggerId, _] = ecm.getUnique<StartGameTriggerComponent>();
        if (eId == startTriggerId)
        {
            ecm.add<GameEvent>(eId, GameEvents::NEXT_STAGE);
        }

        deathEvents.inspect([&](const DeathEvent &deathEvent) {
            auto [pointsComps] = ecm.get<PointsComponent>(eId);
            if (!pointsComps)
                return;

            ecm.add<ScoreEvent>(deathEvent.killedBy, eId);
        });

        ecm.add<DeathComponent>(eId);
    });

    return cleanup;
};
}; // namespace Systems::Death
