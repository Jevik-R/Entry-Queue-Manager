# Entry Queue Manager

Capstone Project  |  Mentor: Prof. Arpit Rana

---

## Problem Statement

You need to build an **Entry Queue Manager** for a **stadium** with `N` entry gates. As attendees arrive, they can:

1. Join any available queue  
2. Switch to another queue if it results in quicker entry  

The system provides:

-  **(i)** Estimated **waiting time** at each gate (assuming a constant entry time `p` minutes per person)  
-  **(ii)** **Queue switch suggestions** for faster access  

The system is **optimized to minimize** total time for `M` people to enter the stadium.

### Note:
> “Initial random assignment of M/2 people” means that half the attendees (i.e., M/2 people) are already distributed randomly across gates. This initial distribution may be uneven.

---

## Approach

We modeled each queue using a **1D array**, where each index `i` represents the number of people at gate `i`. Based on simplicity and performance:

- **Insertion**, **shifting**, and **queue balancing** are performed by direct index manipulation (no heavy STL containers).
- Special handling is included for **group entries** and **VIP queues**.

---

## Features

- Real-time queue monitoring
- Suggest optimal queue for incoming individuals/groups
- Support for:
  - Group/Family entries
  - VIP attendees
- Dynamic queue switching if a better option exists
- Reports estimated wait times for each queue

---

## Core Algorithms

### Data Structures:
- `arr_of_gates[]` → Array holding current queue sizes for regular gates  
- `arr_of_vip[]` → Array holding queue sizes for VIP gates  

### Key Functions:

#### `InsertNew(people, group_t)`
Insert individuals or groups into the shortest queue.

- Time: `O(people * gates)`
- Space: `O(1)`

#### `Shift1(queue_person, standing, poptime, group_t)`
Suggests better queue if attendee is the last in line.

- Time: `O(gates)`
- Space: `O(1)`

#### `Shift()`
Balances load across all queues by shifting from longest to shortest queue.

- Time: `O(gates^2)`
- Space: `O(1)`

Similar functions exist for VIP gates: `InsertNewVip`, `ShiftVip1`, `ShiftV`

---

## Simulation Flow

1. Start with `M/2` people distributed randomly among gates
2. New arrivals handled via `InsertNew()` or `InsertNewVip()`
3. Attendees can **shift** queues if:
   - They're the last in the current queue
   - Another queue offers faster entry
4. Periodic `Shift()` functions redistribute queues for overall load balancing

---

## Time and Space Complexity Summary

| Function       | Time Complexity           | Space Complexity |
|----------------|---------------------------|------------------|
| InsertNew      | O(people * gates)         | O(1)             |
| InsertNewVip   | O(peopleVip * VipGates)   | O(1)             |
| Shift1         | O(gates)                  | O(1)             |
| ShiftVip1      | O(VipGates)               | O(1)             |
| Shift          | O(gates²)                 | O(1)             |
| ShiftV         | O(VipGates²)              | O(1)             |

---

**Team Members**:
- Akshada Modak (202301485)
- Maanav Gurubaxani (202301438)
- Harita Rathod (202301211)
- Jevik Rakholiya (202301276)

