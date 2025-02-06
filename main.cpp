/*****************************************************************//**
 * \file    main.cpp
 * \brief   SplashStages Class
 * 
 * \author  gh Corgice @IceSandwich
 * \date    February 2025
 * \license MIT
 *********************************************************************/

#include <iostream>
#include <chrono>
#include <thread>

class SplashStages {
public:
    void invoke() {
        invoke(&SplashStages::initBrush, &SplashStages::initUI, &SplashStages::initAll);
    }
protected:
    bool initBrush() {
        std::cout << "-- initBrush" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return false;
    }

    // return true to stop
    bool initUI() {
        std::cout << "-- initUI" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return true;
    }

    bool initAll() {
        std::cout << "-- initAll" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return false;
    }

private:
    template <typename ...T>
    bool invoke(const T ...stages) {
        int i = 0;
        return (... && (std::cout << "Runing " << ++i << "/" << sizeof...(stages) << std::endl, !(this->*stages)()));
    }
};

int main() {
    SplashStages ss;
    ss.invoke();
    return 0;
}