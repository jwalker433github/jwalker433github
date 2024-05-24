// tests/main_test.cpp
#include "gtest/gtest.h"
#include "iobject.h"

TEST(IObjectTest, ObjectId) {
    std::string testId = "testId";
    IObject obj(testId);
    ASSERT_EQ(obj.getObjectId(), testId);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
