package pro_con;
import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ProducerConsumer {
    private static int count = 0; //��ʾĿǰ�н绺������Ʒ����
    private final int  FULL  = 5; //�н绺�����������Ϊ5
    private static String  LOCK  = "LOCK"; //��

    class Producer implements Runnable {  //�������߳�
        @Override
        public void run() {
            for (int i = 0; i < 5; i++) { //ÿ���������������5����Ʒ
                try {
                	int sleeptime = (int)(300+Math.random()*(501)); //�������һ��300��800֮�������
                    Thread.sleep(sleeptime);  //���ⵥ����һ��������ռ��˯��0.3��0.8��֮������һ��ʱ��
                } catch (Exception e) {
                    e.printStackTrace();
                }
                synchronized (LOCK) { //��֤ͬһʱ��ֻ��һ���߳���ִ�иô���飬�γ�ͬ������
                    while (count == FULL) {  //���н绺��������ʱ��������ֹͣ������wait����ȴ�
                        try {
                            LOCK.wait();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    count++;
                    System.out.println("��ǰ�߳���Ϊ:"+Thread.currentThread().getName() + "�����ߣ�����һ����Ʒ����������Ʒ����Ϊ:" + count);
                    LOCK.notifyAll();  //���������򻺳�������һ����Ʒʱ���������ȴ����̷߳�����ִ�е�֪ͨ
                }
            }
        }
    }

    class Consumer implements Runnable { //�������߳�
        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {  //ÿ���������������5����Ʒ
                try {
                	int sleeptime = (int)(500+Math.random()*(501));//�������һ��300��800֮�������
                    Thread.sleep(sleeptime);  //���ⵥ����һ��������ռ��˯��0.3��0.8��֮������һ��ʱ��
                } catch (InterruptedException e1) {
                    e1.printStackTrace();
                }
                synchronized (LOCK) {  //��֤ͬһʱ��ֻ��һ���߳���ִ�иô���飬�γ�ͬ������
                    while (count == 0) {  //���н绺����Ϊ��ʱ�������߲������ѣ�wait����ȴ�
                        try {
                            LOCK.wait();
                        } catch (Exception e) {
                        }
                    }
                    count--;
                    System.out.println("��ǰ�߳���Ϊ:"+Thread.currentThread().getName() + "�����ߣ�����һ����Ʒ����������Ʒ����Ϊ:" + count);
                    LOCK.notifyAll();  //�����������ѻ�������һ����Ʒʱ���������ȴ����̷߳�����ִ�е�֪ͨ
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        ProducerConsumer obj = new ProducerConsumer();
        new Thread(obj.new Producer()).start();   //3�������ߺ�3��������
        new Thread(obj.new Producer()).start();
        new Thread(obj.new Producer()).start();
        new Thread(obj.new Consumer()).start();
        new Thread(obj.new Consumer()).start();
        new Thread(obj.new Consumer()).start();
    }
}
