import java.util.Scanner;

import java.util.ArrayList;

public class Main {


    public static void main(String a[])
 {

     ArrayList<Integer> buffer=new ArrayList</*Integer*/> ();

     Thread t1=new Thread (new P(buffer));

     Thread t2=new Thread(new C(buffer));

     t1.start();

     t2.start();
 }

}

class C implements Runnable
{
    
    ArrayList<Integer>b=null;

    final int limit=10;

    int i=10;

    C(ArrayList<Integer> buffer)
    {

        b=buffer;

    }

   

    public void run()

    {

        while(true)

        {

            try{

                i--;

                consumer(i);

            }

            catch(InterruptedException e)

            {

                System.out.println(e);

            }

        }

    }

   

    public void consumer(int i) throws InterruptedException

    {

        synchronized(b)

        {

            while(b.size()==0)

            {

                System.out.println("Consumer is waiting for consumer to consume");

                b.notify();

            }

        }

       

        synchronized(b)

        {

            b.remove(i);

            System.out.println("Consumed item is "+i);

            Thread.sleep(100);

            b.notify();

        }

    }
}

class P implements Runnable

{

    ArrayList<Integer>b=null;

    final int limit=10;

    int i=0;

   

    P(ArrayList<Integer> buffer)

    {

        b=buffer;

    }

   

    public void run()

    {

        while(true)

        {

            try{

                i++;

                produce(i);

            }

            catch(InterruptedException e)

            {

                System.out.println(e);

            }

        }

    }

   

    public void produce(int i) throws InterruptedException

    {

        synchronized(b)

        {

            while(b.size()==limit)

            {

                System.out.println("Producer is waiting for consumer to consume");

                b.wait();

            }

        }

       

        synchronized(b)

        {

            b.add(i);

            System.out.println("Added item are "+i);

            Thread.sleep(100);

            b.notify();

        }

    }

}