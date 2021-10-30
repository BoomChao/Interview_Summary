

//Leetcode第134题 : Gas Station 
//寻找加油站的起点


int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
{
    int sumGas = 0;
    for(int num1 : gas) {
        sumGas += num1;
    }

    int sumCost = 0;
    for(int num2 : cost) {
        sumCost += num2;
    }

    //如果总油量小于总消耗量,则一定跑不完一圈
    //否则肯定能跑完一圈
    if(sumGas < sumCost) return -1;

    //累计一下剩余油量,如果剩余油量小于0,则说明到达不了下一站
    //那么就从下一站开始走,将下一站设为起点
    int start = 0;
    int costGas = 0;
    for(int i = 0; i < gas.size(); i++)
    {
        costGas += gas[i] - cost[i];
        if(costGas < 0) {
            start = j + 1;
            costGas = 0;
        }

    }

    return start;

}


//上面的更简洁的写法

int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
{
    int index = 0;
    int total = 0;
    int tank = 0;

    for(int i = 0; i < gas.size(); i++)
    {
        int consume = gas[i] - cost[i];
        tank += consume;
        if(tank < 0) {
            index = i + 1;
            tank = 0;
        }

        total += consume;
    }

    return total < 0 ? -1 : index;

}