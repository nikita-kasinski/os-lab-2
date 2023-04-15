# Exercise 2 ОS
## Made by Nikita Kasinski
### Overview
The app comprises main process and two utility threads: minmax thread and average thread. Minmax thread calculates minimum and maximum in the array, average thread calculates array average. Main process substitutes average value for minimal and maximum values.
### Tools
* gcc - compiler
* make - build automation tool
* gtest - library for creating unit tests on c++
* gcov, lcov - tools to test code coverage
### CI/CD
CI/CD is made via Github Actions. There are build and test jobs in the workflow file, which enables project to be built and tested on a clean remote runner.
### Manual running, building, testing and testing code coverage
To perform any listed task several tools and libraries are required:
* gcc
* make 
* gtest (when testing code and code coverage)
* gcov (when testing code coverage)
* lcov (when testing code coverage)

Prepared targets:
* make run - launching the app
* make build - building the app
* make test - running tests
* make report - testing code coverage

