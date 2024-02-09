#include "gtest/gtest.h"
#include "../include/Awards.h"
#include "gmock/gmock.h"
using namespace awards;
using namespace testing;

class RankListStub : public RankList {
public:
    RankListStub() : currentIndex(0) {} //make mock implementation

    std::string getNext() override {
        std::string returnValue;

        if (currentIndex >= listSize) {
            currentIndex = 0;
        }

        returnValue = names[currentIndex];
        ++currentIndex;
        
        return returnValue;
    }

private:
    int currentIndex = 0;
    std::string names[3] = {"Arya", "Ben", "Charlie"};
    int listSize = 3;
};

class MockAwardCeremonyActions : public AwardCeremonyActions {
    public:
    MOCK_METHOD(void, playAnthem, (), (override));
    MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
    MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
    MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
    MOCK_METHOD(void, awardGold, (std::string recipient), (override));
    MOCK_METHOD(void, performAwardCeremony, ());
};

TEST(MockRankListTests, Test3Names) {
    RankListStub mockRankList;
    EXPECT_EQ(mockRankList.getNext(), "Arya");
    EXPECT_EQ(mockRankList.getNext(), "Ben");
    EXPECT_EQ(mockRankList.getNext(), "Charlie");
}

TEST(AwardTests, CheckAwardFunctionOrder) {
    RankListStub mockRankList;
    MockAwardCeremonyActions mockAwardActions;

    EXPECT_CALL(mockAwardActions, playAnthem());
    EXPECT_CALL(mockAwardActions, awardBronze("Arya"));
    EXPECT_CALL(mockAwardActions, awardSilver("Ben")); 
    EXPECT_CALL(mockAwardActions, awardGold("Charlie")); 
    EXPECT_CALL(mockAwardActions, turnOffTheLightsAndGoHome());

    performAwardCeremony(mockRankList, mockAwardActions);
}
