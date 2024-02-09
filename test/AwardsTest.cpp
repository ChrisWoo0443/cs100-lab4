#include "gtest/gtest.h"
#include "../include/Awards.h"
#include "gmock/gmock.h"

using namespace awards;

class MockAwardCeremonyActions : public AwardCeremonyActions
{
    public:
        MOCK_METHOD(void, playAnthem, (), (override));
        MOCK_METHOD(void, awardBronze, (string recipient), (override));
        MOCK_METHOD(void, awardSilver, (string recipient), (override));
        MOCK_METHOD(void, awardGold, (string recipient), (override));
        MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
};