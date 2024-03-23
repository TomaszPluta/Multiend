# Multiend
Multi edpoint message disaptcher


**System Architecture Overview:**

The system architecture consists of a centralized message broker responsible for managing the communication flow between various endpoints. Endpoints represent the sources and destinations of messages within the system and can take various forms, including but not limited to:

- Processes on the same system
- Computers in the local network
- Bluetooth-connected devices
- UART port connections
- SMS messages sent over cellular networks
- Radio-controlled channels
- IRC messages
- And more...
  
**Components:**

Endpoints: Endpoints are entities within the system responsible for sending and receiving messages. Each endpoint represents a distinct source or destination of messages and can take various forms depending on the communication medium.

Broker: The broker serves as the central hub for message routing and coordination within the system. It facilitates the exchange of messages between endpoints by employing a pool of worker threads.

Worker Threads: Worker threads are dedicated processing units within the broker responsible for handling incoming messages and dispatching them to their respective destination endpoints. In this configuration, the broker employs two worker threads labeled WorkerThread1 and WorkerThread2.

**Message Flow:**

Message Transmission: Messages originate from endpoints of various kinds and are transmitted to the broker for processing.

Broker Processing: Upon receiving a message, the broker routes it to an available worker thread for processing.

Worker Thread Dispatch: Worker threads handle incoming messages and dispatch them to their designated destination endpoints based on predefined routing logic.

Endpoint Reception: Finally, the messages reach their destination endpoints, which can take various forms, where they are received and processed accordingly.

This architecture provides a scalable and efficient mechanism for managing message communication within the system, ensuring timely delivery and processing of messages between endpoints of diverse forms and communication mediums.





                             +-------+
                             | Broker|
                             +---+---+
                                 |
            +------------+-------+--------+------------+
            |            |                |            |
       +----v----+   +---v---+      +-----v-----+   +--v---+
       |Endpoint9|   |Message|      |WorkerThread|   |Endpoint3|
       +----+----+   +---+---+      +-----+-----+   +--^---+
            |            |                |            |
       +----v----+   +---v---+      +-----v-----+   +--v---+
       |Endpoint4|   |Message|      |WorkerThread|   |Endpoint7|
       +----+----+   +---+---+      +-----+-----+   +--^---+
            |            |                |            |
       +----v----+   +---v---+      +-----v-----+   +--v---+
       |Endpoint11|  |Message|      |WorkerThread|  |Endpoint2|
       +----------+  +-------+      +------------+  +--^---+
                                                      |
                                                 +----v----+
                                                 |Endpoint14|
                                                 +---------+
