#ifndef RESULT_TEST_COPY_ONLY_ENTITY_HPP
#define RESULT_TEST_COPY_ONLY_ENTITY_HPP

struct CopyOnlyEntity {
    CopyOnlyEntity() = default;
    CopyOnlyEntity(const CopyOnlyEntity&) = default;
    CopyOnlyEntity(CopyOnlyEntity&&) = delete;
    CopyOnlyEntity& operator=(const CopyOnlyEntity&) = default;
    CopyOnlyEntity& operator=(CopyOnlyEntity&&) = delete;
};

#endif