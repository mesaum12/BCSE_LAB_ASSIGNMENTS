package java_assignments2;
import java.lang.Runnable;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class ProducerConsumerOps
{
    Queue<Integer>q=new LinkedList<>();
    private int MAX_CAPACITY=3;
    private static int item_count=1;
    ProducerConsumerOps(int capacity)
    {
        MAX_CAPACITY=capacity;
    }
    public synchronized void set()
    {
        while(q.isEmpty()==false)
        {
            try
            {
                wait();
            }
            catch(InterruptedException e)
            {
                e.getStackTrace();
            }
        }
        while(q.size()!=MAX_CAPACITY)
        {
            q.add(item_count);
            System.out.println("Producer added item #"+item_count);
            item_count++;
        }
        notify();//this notifies the waiting consumer
    }
    public synchronized void get()
    {
        while(q.isEmpty())
        {
            try
            {
                wait();
            }
            catch(InterruptedException e)
            {
                e.getStackTrace();
            }
        }
        while(!q.isEmpty())
        System.out.println("Consumed Item #"+q.poll());
        notify();//this notifies the waiting producer

    }
}
class Producer implements Runnable
{
    ProducerConsumerOps o;
    Producer(ProducerConsumerOps op1)
    {
       o=op1;
       Thread t=new Thread(this,"ProducerThread");
       t.start();
    }

    @Override
    public void run() {
        //here we need to call the set method
        int x=0;int count=10;
        while(x<count)
        {
            try {
                o.set();
                x++;
                Thread.sleep(1000);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}
class Consumer implements Runnable
{
    ProducerConsumerOps o;
    Consumer(ProducerConsumerOps o)
    {
        this.o=o;
        Thread t=new Thread(this,"ConsumerThread");
        t.start();
    }

    @Override
    public void run() {
        int x=0,count=10;
        while(x++<10)
        {
            try {
                o.get();
                Thread.sleep(500);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}
public class Assign2_7 {
    public static void main(String[] args) {
        System.out.println("Enter the size of the buffer :");
        int size;
        Scanner sc=new Scanner(System.in);
        size=sc.nextInt();
        ProducerConsumerOps o=new ProducerConsumerOps(size);
        new Producer(o);
        new Consumer(o);
    }
}
