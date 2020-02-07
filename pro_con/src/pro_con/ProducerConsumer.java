package pro_con;
import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ProducerConsumer {
    private static int count = 0; //表示目前有界缓冲区产品数量
    private final int  FULL  = 5; //有界缓冲区最大容量为5
    private static String  LOCK  = "LOCK"; //锁

    class Producer implements Runnable {  //生产者线程
        @Override
        public void run() {
            for (int i = 0; i < 5; i++) { //每个生产者最多生产5个产品
                try {
                	int sleeptime = (int)(300+Math.random()*(501)); //随机产生一个300到800之间的数字
                    Thread.sleep(sleeptime);  //避免单独被一个进程抢占，睡眠0.3到0.8秒之间的随机一个时间
                } catch (Exception e) {
                    e.printStackTrace();
                }
                synchronized (LOCK) { //保证同一时刻只有一个线程能执行该代码块，形成同步互斥
                    while (count == FULL) {  //当有界缓冲区已满时，生产者停止生产，wait进入等待
                        try {
                            LOCK.wait();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    count++;
                    System.out.println("当前线程名为:"+Thread.currentThread().getName() + "生产者，生产一个产品，缓存区产品数量为:" + count);
                    LOCK.notifyAll();  //当生产者向缓冲区放入一个产品时，向其他等待的线程发出可执行的通知
                }
            }
        }
    }

    class Consumer implements Runnable { //消费者线程
        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {  //每个消费者最多消费5个产品
                try {
                	int sleeptime = (int)(500+Math.random()*(501));//随机产生一个300到800之间的数字
                    Thread.sleep(sleeptime);  //避免单独被一个进程抢占，睡眠0.3到0.8秒之间的随机一个时间
                } catch (InterruptedException e1) {
                    e1.printStackTrace();
                }
                synchronized (LOCK) {  //保证同一时刻只有一个线程能执行该代码块，形成同步互斥
                    while (count == 0) {  //当有界缓冲区为空时，消费者不能消费，wait进入等待
                        try {
                            LOCK.wait();
                        } catch (Exception e) {
                        }
                    }
                    count--;
                    System.out.println("当前线程名为:"+Thread.currentThread().getName() + "消费者，消费一个产品，缓存区产品数量为:" + count);
                    LOCK.notifyAll();  //当消费者消费缓冲区的一个产品时，向其他等待的线程发出可执行的通知
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        ProducerConsumer obj = new ProducerConsumer();
        new Thread(obj.new Producer()).start();   //3个生产者和3个消费者
        new Thread(obj.new Producer()).start();
        new Thread(obj.new Producer()).start();
        new Thread(obj.new Consumer()).start();
        new Thread(obj.new Consumer()).start();
        new Thread(obj.new Consumer()).start();
    }
}
