#pragma once
//Travis Guthrie cs114
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
namespace PictureBoxArray {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(448, 335);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		

		array<PictureBox^, 2> ^pictures = gcnew array <PictureBox^, 2>(9, 9);// an array of picture boxes
		int x = 0;
		int y = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				pictures[i,j] = gcnew PictureBox;//creates a picturebox to be put in the array
				pictures[i,j]->Location = Point(x, y);
				pictures[i,j]->Parent = this;
				pictures[i,j]->Size::set(Drawing::Size(30, 30));
				pictures[i,j]->BackColor = Color::Red;
				
				x += 35;//puts the next box to the right of the previous
			}
			y += 35;//starts putting boxes on the level below the previous
			x = 0; //starts back all the way to the left
		}
		

		
		//opens a file and takes out the first value
		std::ifstream infile;
		infile.open("InFile.txt");
		std::string junk;
		infile >> junk;

		using namespace std;
		while (!infile.eof())
		{
			int i;
			int j;
			
			infile >> i;//takes in a coordinate from the file
			infile >> j;

			pictures[i, j]->Load("dwc.gif"); //displays the image in the picture box at that point in the array
			
		}
		
	}
	};
}
