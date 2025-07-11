
#include <iostream>
#include <random>
using namespace std;
class EntryQueueManager
{
private:
    int Gates;
    int VipGates;
    int population;
    int Vip_population;
    int *arr_of_gates;
    int *arr_of_vip;


public:
    void SetData(int pop, int gates_1, int vip_gates, int vip_pop)
    {
        Vip_population = vip_pop;
        Gates = gates_1;
        population = pop;
        VipGates = vip_gates;
        arr_of_gates = new int[Gates];
        arr_of_vip = new int[VipGates];

        for (int i = 0; i < Gates; ++i)
        {
            arr_of_gates[i] = 0;

        }
        for(int i=0;i<VipGates;++i){
            arr_of_vip[i]=0;
        }
    }
    EntryQueueManager(){}


    void RandomAssignment_initial()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> gate(0, Gates - 1);


        int initialPeople = population / 2;


        for (int i = 0; i < initialPeople; ++i)
        {
            int gateNumber = gate(gen);
            arr_of_gates[gateNumber]++;
        }
    }

    int waiting_time(int qno,int t){

        return arr_of_gates[qno-1]*t;
    }
    int waiting_time_vip(int qno,int t){

        return arr_of_vip[qno-1]*t;
    }
    void RandomAssignmentVip_initial()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> gateVip(0, VipGates - 1);


        int initialPeople = Vip_population / 2;


        for (int i = 0; i < initialPeople; ++i)
        {
            int gateNumber = gateVip(gen);
            arr_of_vip[gateNumber]++;
        }
    }


    int RandomAssignment(int Remaining)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> gate(0, Remaining);
        return gate(gen);
    }
    int RandomAssignmentVip(int RemainingV)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> gateVip(0, RemainingV);
        return gateVip(gen);
    }


    void display()
    {
        for (int counter = 0; counter < Gates; counter++)
        {
            cout << "The number of members in Gate " << counter + 1 << " is : " << arr_of_gates[counter] << endl;
        }


        for (int counter = 0; counter < VipGates; counter++)
        {
            cout << "The number of members in VIPGate " << counter + 1 << " is : " << arr_of_vip[counter] << endl;
        }
    }


    int InsertNew(int people, int group_t)
    {
        int index_of_min = 0;
        int counter;
        int min = arr_of_gates[0];
        // min is the no. of people in queue containing the least amount of people
        // index_of_min is the queue no. of said queue
        while (people != 0)
        {
            min = arr_of_gates[0];
            for (counter = 0; counter < Gates; counter++)
            {
                if (arr_of_gates[counter] <= min)
                {
                    min = arr_of_gates[counter];
                    index_of_min = counter;
                }
            }
            if (group_t == 0)
            {
                arr_of_gates[index_of_min]++;
                people--;
            }
            else
            {
                arr_of_gates[index_of_min] += group_t;
                people--;
            }
        }
        return index_of_min + 1;
    }


    int InsertNewVip(int peopleVip, int groupVip_t)
    {
        int index_of_min = 0;
        int  counter;
        int  min = arr_of_vip[0];
        // min is the no. of people in queue containing the least amount of people
        // index_of_min is the queue no. of said queue
        while (peopleVip != 0)
        {
            min = arr_of_vip[0];
            for (counter = 0; counter < VipGates; counter++)
            {
                if (arr_of_vip[counter] <= min)
                {
                    min = arr_of_vip[counter];
                    index_of_min = counter;
                }
            }
            if (groupVip_t == 0)
            {
                arr_of_vip[index_of_min]++;
                peopleVip--;
            }
            else
            {
                arr_of_vip[index_of_min] += groupVip_t;
                peopleVip--;
            }
        }
        return index_of_min + 1;
    }


    int people_in_queue()
    {
        int sum = 0;
        for (int counter = 0; counter < Gates; counter++)
        {
            sum += arr_of_gates[counter];
        }
        return sum;
    }


    int people_in_vipQueue()
    {
        int sum = 0;
        for (int counter = 0; counter < VipGates; counter++)
        {
            sum += arr_of_vip[counter];
        }
        return sum;
    }


    void shiftVip1(int queue_person, int standing, int poptime, int groupVip_t)
    {
        int size = arr_of_vip[queue_person];
        if (size > standing)
        {
            if (groupVip_t != 0)
            {
                cout << "Your last group member is not the last member in the queue . You cannot Shift ." << endl;
                cout << "It will take " << poptime * standing << " mins from your current position for all members of group to reach stadium ." << endl;
            }
            else
            {
                cout << "You are not the last member in the queue . You cannot Shift ." << endl;
                cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
            }
        }
        else if (size == standing)
        {
            int min = arr_of_vip[0]; // change
            int a = -1;
            for (int j = 0; j < VipGates; j++)
            {
                if (min >= arr_of_vip[j])
                {
                    a = j;
                    min = arr_of_vip[j];
                }
            }
            if (a != -1 && (min + groupVip_t) < arr_of_vip[queue_person])
            {
                cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
                cout << "You have to move to queue " << a+1 << endl;
                if (groupVip_t != 0)
                {
                    (arr_of_vip[a]) += groupVip_t;
                    (arr_of_vip[queue_person]) -= groupVip_t;
                }
                else
                {
                    (arr_of_vip[a])++;
                    (arr_of_vip[queue_person])--;
                }
                cout << "It will take " << poptime * (arr_of_vip[a]) << " mins from your new position to reach stadium ." << endl;
            }
            else
            {
                if (groupVip_t != 0)
                {
                    cout << "You and your group members are at the most optimised place ." << endl;
                    cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
                }
                else
                {
                    cout << "You are at the most optimised place ." << endl;
                    cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
                }
            }
        }


        else
        {
            cout << "Enter your accurate standing in your queue" << endl;
        }
    }
    void shift1(int queue_person, int standing, int poptime, int group_t)
    {
        int size = arr_of_gates[queue_person];
        if (size > standing)
        {
            if (group_t != 0)
            {
                cout << "Your last group member is not the last member in the queue . You cannot Shift ." << endl;
                cout << "It will take " << poptime * standing << " mins from your current position for all members of group to reach stadium ." << endl;
            }
            else
            {
                cout << "You are not the last member in the queue . You cannot Shift ." << endl;
                cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
            }
        }
        else if (size == standing)
        {
            int min = arr_of_gates[0]; // change
            int a = -1;
            for (int j = 0; j < Gates; j++)
            {
                if (min >= arr_of_gates[j])
                {
                    a = j;
                    min = arr_of_gates[j];
                }
            }
            if (a != -1 && (min + group_t) < arr_of_gates[queue_person])
            {
                cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
                cout << "You have to move to queue " << a+1 << endl;
                if (group_t != 0)
                {
                    (arr_of_gates[a]) += group_t;
                    (arr_of_gates[queue_person]) -= group_t;
                }
                else
                {
                    (arr_of_gates[a])++;
                    (arr_of_gates[queue_person])--;
                }
                cout << "It will take " << poptime * (arr_of_gates[a]) << " mins from your new position to reach stadium ." << endl;
            }
            else
            {
                if (group_t != 0)
                {
                    cout << "You and your group members are at the most optimised place ." << endl;
                    cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
                }
                else
                {
                    cout << "You are at the most optimised place ." << endl;
                    cout << "It will take " << poptime * standing << " mins from your current position to reach stadium ." << endl;
                }
            }
        }


        else
        {
            cout << "Enter your accurate standing in your queue" << endl;
        }
    }


    void shift()
    {
        for (int i = 0; i < Gates; i++)
        {
            int min = arr_of_gates[0];
            int a = -1;
            for (int j = 0; j < Gates; j++)
            {
                if (min >= arr_of_gates[j])
                {
                    a = j;
                    min = arr_of_gates[j];
                }
            }
            if (a != -1 && min < arr_of_gates[i])
            {
                (arr_of_gates[a])++;
                (arr_of_gates[i])--;
            }
        }
    }


    void shiftV()
    {
        for (int i = 0; i < VipGates; i++)
        {
            int min = arr_of_vip[0];
            int a = -1;
            for (int j = 0; j < VipGates; j++)
            {
                if (min >= arr_of_vip[j])
                {
                    a = j;
                    min = arr_of_vip[j];
                }
            }
            if (a != -1 && min < arr_of_vip[i])
            {
                (arr_of_vip[a])++;
                (arr_of_vip[i])--;
            }
        }
    }
    void pop()
    {
        for (int counter = 0; counter < Gates; counter++)
        {
            if (arr_of_gates[counter] != 0)
            {
                (arr_of_gates[counter])--;
            }
        }
    }
    void popV()
    {
        for (int counter = 0; counter < VipGates; counter++)
        {
            if (arr_of_vip[counter] != 0)
            {
                (arr_of_vip[counter])--;
            }
        }
    }
};
