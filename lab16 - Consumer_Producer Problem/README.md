# LAB ACTIVITY 16 CONSUMER/PRODUCER
## A. Brief Description Of Consumer/producer
The consumer/ producer problem is a common example of the synchronisation problem. According to (Zhang et al. 2009) both the produce & consumer share a common fixed-length buffer. The producer is responsible for data insertion while the consumer consumes data simultaneously. The problem is to ensure that both processes do not clash i.e. The producer does not add more data to a filled buffer and the consumer does not pop data from an empty buffer.
## B. Modified Code To Solve Consumer/producer Problem. Showing Different Buffer Lengths And Different Speeds.

### bufferlength = 6

![bufferlength=6](https://i.postimg.cc/tCHL2Hjm/image.png)

### bufferlength=4

![bufferlength=4](https://i.postimg.cc/k4Lz2Nx1/image.png)

Because the consumer and producer slots are stored relative to the buffer length, ie bufferLength + 1 or +2, a change in bufferlength is easy and will not need to reallocate a specific slot for the producer & consumer.

Rsleep() on the consumer, consumer sleeps for a random amount of time
![Rsleep()](https://i.postimg.cc/9MPZ9C96/image.png)

Because this script utilizes a ring buffer, even if the consumer runs at a different speed as the producer, the producer will continue to produce while the consumer will consume only when the producer has finish producing, there by having no collisions. We can also see that the producer will only produce when the consumer has finished consuming that item.

Rsleep() on the producer, producer sleeps for random amount of time.
![ringbuffer](https://i.postimg.cc/yxvRfjvn/image.png)

Because of our ring buffer, even though the producer is sleeping, the consumer will not consume until the producer is done producing. This also shows that a collision does not occur even when the producer and consumer are running at different speeds.