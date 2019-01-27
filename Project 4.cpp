#include <iostream>
#include <fstream>
//allows the use of strings
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;
	string inputf, outputf;
	double file_value, max = INT_MIN, min = INT_MAX, sum = 0, ave;
	int sep, count = 0;

	cout << "What file would you like to read from ? \n";
	cin >> inputf;
	//tries to open the file that the user inputs
	infile.open(inputf);

	if (!infile.is_open())
	{
		int blockcount = 0;
		//allows the user 3 extra chances to insert file name
		//if the file isnt open AND blockcount is less that 3, loop
		while (blockcount < 3 && !infile.is_open())
		{
			cout << "\nCannot Find File, Please Insert Correct Name ! \n";
			cin >> inputf;
			infile.open(inputf);
			blockcount++;
		}
	}
	//If the file is opened continue
	if (infile.is_open())
	{
		//allows the user to name the output file
		cout << "\nWhat would you like your new file to be named? \n";
		cin >> outputf;
		//creates the output file
		outfile.open(outputf);
		//for spacing
		cout << endl;

		outfile << "Purpose:This program reads in numbers from a file, then \n";
		outfile << "outputs those numbers to a new file. it also prints out \n";
		outfile << "the  Maximum and Minimum numbers along with the Sum and \n";
		outfile << "Average of the numbers.\n\n";

		while (infile >> file_value)
		{
			sep = count % 12;
			//after 12 numbers go to next line
			if (sep == 0)
				outfile << endl;
			//Prints value found in the input file within 5 spaces
			outfile << setw(5) << file_value << " ";		
			//find the maximum value no matter the order of the numbers
			if (file_value > max)
				max = file_value;
			//find the minimum value no matter the order of the numbers
			if (file_value < min)
				min = file_value;
			//adds all values together
			sum += file_value;
			//counts how many time the loop iterates 
			count++;
		}
		//for spacing
		outfile << endl << endl;

		//calculations
		ave = sum / count;

		//additional printout
		outfile << setw(8) << left << "Largest " << ": "
				<< setw(6) << right << max << endl;
		outfile << setw(8) << left << "Minimum " << ": "
				<< setw(6) << right << min << endl;
		outfile << setw(8) << left << "Sum " << ": "
				<< setw(6) << right << sum << endl;
		outfile << setw(8) << left << "Average " << ": "
				<< setw(11) << right << ave << endl;
		cout << endl;

		//Closes Files that were open
		infile.close();
		outfile.close();
	}
	else
		//if the file still isnt opened 
		cout << "\n Sigh, I give up....BYE!! \n\n";

	system("pause");
	return 0;
}
