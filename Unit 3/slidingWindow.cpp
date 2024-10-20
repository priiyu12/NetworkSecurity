#include <iostream>
#include <thread>
using namespace std;

class SlidingWindow
{
public:
  	SlidingWindow(int ws, int tf) {
	    windowSize = ws;
	    totalFrames = tf;
	    frame = 1;
	}

	void sendFrames()
	{
		while (frame <= totalFrames){
			int sentFrames = 0;
        	for (int i = 0; i < windowSize; i++) {
            	cout << "Sending frame " << frame + i << endl;
            	sentFrames++;
        	}

        	this_thread::sleep_for(chrono::milliseconds(1000));

        	int ackReceived = 0;
        	for (int i = 0; i < sentFrames; ++i) {
	            int ack = rand() % 2;
	            if (ack == 1) {
	                cout << "ACK received for frame " << frame + i << endl;
	                ackReceived++;
	            } 
	            else {
	                cout << "Frame " << frame + i << " lost, resending..." << endl;
	                break;
   		        }
        }

        cout << "------------------" << endl;

        // Slide the window forward by the number of successfully acknowledged frames
        frame += ackReceived;
		}
		cout << "All frames sent and acknowledged successfully!" << endl;
	}

private:
	int windowSize, totalFrames, frame;
};

int main()
{
	int windowSize, totalFrames;
	cout << "Enter window size : ";
	cin >> windowSize;
	cout<<"Enter total frames : ";
	cin >> totalFrames;

	SlidingWindow protocol(windowSize, totalFrames);
	protocol.sendFrames();
	return 0;
}
