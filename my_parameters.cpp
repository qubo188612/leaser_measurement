#include "my_parameters.h"

my_parameters *my_parameters::Get()
{
    static my_parameters fun;
    return &fun;
}

my_parameters::my_parameters()
{
    cam=cam->Get();
}

my_parameters::~my_parameters()
{

}
