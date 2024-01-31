#ifndef RESULT_TEST_MOVE_ONLY_ENTITY_HPP
#define RESULT_TEST_MOVE_ONLY_ENTITY_HPP

struct MoveOnlyEntity {
    MoveOnlyEntity() = default;
    MoveOnlyEntity(const MoveOnlyEntity&) = delete;
    MoveOnlyEntity(MoveOnlyEntity&&) = default;
    MoveOnlyEntity& operator=(const MoveOnlyEntity&) = delete;
    MoveOnlyEntity& operator=(MoveOnlyEntity&&) = default;
};

#endif