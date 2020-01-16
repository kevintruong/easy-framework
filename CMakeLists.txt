cmake_minimum_required(VERSION 3.15)
project(eframework C)

set(CMAKE_C_STANDARD 11)

include_directories(CuTest)
include_directories(eFrameWork/eInclude)
include_directories(eFrameWork/Inc)
include_directories(Test/TestModule/Inc)

add_executable(eframework
        eFrameWork/eInclude/eError.h
        eFrameWork/eInclude/eInclude.h
        eFrameWork/eInclude/eTypes.h
        eFrameWork/Inc/eOsal.h
        eFrameWork/Inc/eOsalTaskHandle.h
        eFrameWork/Inc/eTask.h
        eFrameWork/Inc/eTaskId.h
        eFrameWork/Inc/eTimer.h
        eFrameWork/Inc/eTimerHandler.h
        eFrameWork/Src/eOsal.c
        eFrameWork/Src/eOsalTaskHandle.c
        eFrameWork/Src/eTask.c
        eFrameWork/Src/eTimerHandler.c
        Test/eTestMain/eMain.c
        Test/TestModule/Inc/eTestModule.h
        Test/TestModule/Src/eTestModule.c
        eFrameWork/Src/eLogger.c eFrameWork/Inc/eLogger.h)
