#ifndef RESULT_TEST_NORMAL_ENTITY_HPP
#define RESULT_TEST_NORMAL_ENTITY_HPP

struct NormalEntity {
    NormalEntity() = default;
    NormalEntity(const NormalEntity&) = default;
    NormalEntity(NormalEntity&&) = default;
    NormalEntity& operator=(const NormalEntity&) = default;
    NormalEntity& operator=(NormalEntity&&) = default;
};

#endif