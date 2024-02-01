[![test](https://github.com/asuka1975/result/actions/workflows/test.yml/badge.svg)](https://github.com/asuka1975/result/actions/workflows/test.yml)
![](https://img.shields.io/github/license/asuka1975/result)
![](https://img.shields.io/github/repo-size/asuka1975/result)
![](https://img.shields.io/github/downloads/asuka1975/result/total)

# Asuka1975's Software Collection - Result

The monadic result library.

This library provide result object with error supported monadic operation.

You can use this class as following code:

```cpp
Result<Error, Value1> result = processSomething();

Output output = result
    .map<Value2>([](Value1 v) {
        return transformValue1(v);
    })
    .flatMap<Value3>([](Value2 v) -> Result<Error, Value3> {
        if(!checkValue2(v)) {
            return createError(v);
        }
        return transformValue2(v);
    })
    .visit(processFinally);
```
