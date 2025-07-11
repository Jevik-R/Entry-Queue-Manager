#include"EntryQueueManager_class.cpp"
int main()
{
   int capacity, gates, poptime, time_of_entry, VG, capacity_vip;
   cout << "Enter the capacity of your stadium: ";
   cin >> capacity;
   cout << "Enter the capacity of VIP people in your stadium: ";
   cin >> capacity_vip;
   cout << "Enter the no of gates to be used for entering the people in the stadium: ";
   cin >> gates;
   cout << "Enter the number of vip gates used for entering the people in the stadium: ";
   cin >> VG;
   cout << "Enter the time required for the pop in mins : ";
   cin >> poptime;
   cout << "Enter the amount of time(in min) for which the entry gates should be open: ";
   cin >> time_of_entry;
   int max_time = time_of_entry / poptime;
   capacity = capacity - capacity_vip;
   gates = gates - VG;
   EntryQueueManager e(capacity, gates, VG, capacity_vip);
   e.RandomAssignment();
   e.RandomAssignmentVip();
   e.display();
   int remaining, remainingV;
   int remaining_total_V = capacity_vip / 2;
   int remaining_total = capacity / 2;
   cout << "Are you a VIP c ? " << endl
        << "Enter 0 if Yes and 1 if No : ";
   int c;
   cin >> c;
   if (c == 0)
   {
       remaining = capacity / 2;
       remainingV = capacity_vip / 2 - 1;
   }
   else if (c == 1)
   {
       remaining = capacity / 2 - 1;
       remainingV = capacity_vip / 2;
   }
   else
   {
       cout << "Enter correct value";
       return 0;
   }
   int timef;
   int a = 0;
   int b = 0;
   while ((remaining_total != 0 || remaining_total_V != 0) && a != max_time)
   {
       int num;
       cout << "Enter 0 to note the people entering else enter any other number : ";
       cin >> num;
       switch (num)
       {
       case 0:
       {
           cout << "Enter 0 if want to enter any queue : " << endl
                << "Enter 1 if you want to shift : " << endl
                << "Enter any other number to continue using the app :";
           int num1;
           cin >> num1;
           if (num1 == 0)
           {
               cout << "Enter the number of people accompanying you : ";
               int group;
               cin >> group;
               group++;
               if (c == 0)
               {
                   if (group == 1)
                   {
                       int moving_queue = e.InsertNewVip(1, b);
                       remaining_total_V--;
                       cout << "You have to move to queue " << moving_queue << endl;
                   }
                   else
                   {
                       b = group;
                       int moving_queue = e.InsertNewVip(1, b);
                       remaining_total_V -= b;
                       remainingV =remainingV- b+1;
                       cout << "You all have to move to VIPqueue " << moving_queue << endl;
                   }
               }
               else
               {
                   if (group == 1)
                   {
                       int moving_queue = e.InsertNew(1, b);
                       remaining_total--;
                       cout << "You have to move to queue " << moving_queue << endl;
                   }
                   else
                   {
                       b = group;
                       int moving_queue = e.InsertNew(1, b);
                       remaining_total -= b;
                       remaining =remaining - b+1;
                       cout << "You all have to move to queue " << moving_queue << endl;
                   }
               }
           }
           else if (num1 == 1)
           {
               cout << "Enter the number of people accompanying you : ";
               int group;
               cin >> group;
               group++;
               if (c == 0)
               {
               }


               else
               {
                   if (group == 1)
                   {
                       int queue_person, standing;
                       cout << "Enter your queue number : ";
                       cin >> queue_person;
                       cout << "Enter your standing number in the queue : ";
                       cin >> standing;
                       e.shift1(queue_person, standing, poptime, b);
                   }
                   else
                   {
                       b = group;
                       int queue_person, standing;
                       cout << "Enter your queue number : ";
                       cin >> queue_person;
                       cout << "Enter the standing of last person of your group in the queue : ";
                       cin >> standing;
                       e.shift1(queue_person, standing, poptime, b);
                   }
               }
           }


           else
           {
               cout << "---" << remainingV << endl;
               int peopleV = e.RandomAssignment2V(remainingV);
               cout << peopleV << endl;
               cout << "RV:" << remainingV << endl;
               cout<<"RVT: "<<remaining_total_V<<endl;
               e.InsertNewVip(peopleV, b);
               remainingV = remainingV - peopleV;
               remaining_total_V = remaining_total_V - peopleV;
               int people = e.RandomAssignment2(remaining);
               cout << people << endl;
               cout << "R:" << remaining;
               cout << "RT:" << remaining_total;
               e.InsertNew(people, b);
               remaining = remaining - people;
               remaining_total = remaining_total - people;
           }
           b = 0;
       }
       default:
       {
           e.shift();
           e.shiftV();
           e.pop();
           e.popV();
           a++;
           e.display();
       }
       }
   }
  timef = a * poptime;
  cout << timef << endl;
  cout << "No new Entry allowed now for entering the line" << endl;
  a = 0;
  remaining = e.people_in_queue();
  cout << remaining;
  if (remaining != 0)
  {




      while (remaining != 0)
      {
          e.shift();
          e.pop();
          a++;
          remaining = e.people_in_queue();
      }
  }
  timef += a * poptime;
  cout << "Total time required for the people to enter is : " << timef << endl;
}
