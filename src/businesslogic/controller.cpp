#include "controller.h"

controller::controller(/* args */)
{
    std::cout << "controller constructed" << std::endl;
}


controller::~controller()
{
}

void controller::generateValues()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    while (true)
    {
        qInfo() << "running controller infinit loop monitor on thread: " << QThread::currentThread();

        auto new_val = distribution(generator);
        m_value = new_val;
        emit valueChanged(new_val);
        QThread::sleep(2);
        if (exit_flag == true) break;
    }

}

int controller::getValue()
{
    return m_value;
}

