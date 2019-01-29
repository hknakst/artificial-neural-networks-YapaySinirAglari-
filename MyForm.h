#pragma once

#include "ysa.h"
#include <atlstr.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <string.h>

namespace YapaySinirAglari {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Bitmap^ surface;
		double *Coordinate = new double[1000];
		int arraySize = 0;
		int *array = new int[30];
		int size = 3;
		double *W = new double[60];
		double *V = new double[100];
		int index = 0;
		int numberof_class;
		/*coordinatelist *list;*/
	private: System::Windows::Forms::MenuStrip^  menuStrip3;
	private: System::Windows::Forms::ToolStripMenuItem^  processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  singleLayerNeuralNetworkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  perceptronToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deltaToolStripMenuItem;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  multiPerceptronToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  multiDeltaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  multilayerNetworkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  twoLayerToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ToolStripMenuItem^  twoLayerWithMomentToolStripMenuItem;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;





	private: System::Windows::Forms::Button^  button2;
	

			
	public:
		
		MyForm(void)
		{
			
			InitializeComponent();
			//pixturebox beyaz bir zemine boyand,
			Color c = Color::FromArgb(255, 255, 255);
			surface = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = surface;
			for (int i = 0; i < pictureBox1->Height; i++)
				for (int j = 0; j < pictureBox1->Width; j++)
				{
					surface->SetPixel(j, i, c);
				}


			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;



	protected:

	private:

		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip3 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->singleLayerNeuralNetworkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->perceptronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiPerceptronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiDeltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multilayerNetworkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->twoLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->twoLayerWithMomentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 600);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// menuStrip3
			// 
			this->menuStrip3->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip3->Location = System::Drawing::Point(0, 0);
			this->menuStrip3->Name = L"menuStrip3";
			this->menuStrip3->Size = System::Drawing::Size(1437, 28);
			this->menuStrip3->TabIndex = 5;
			this->menuStrip3->Text = L"menuStrip3";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->singleLayerNeuralNetworkToolStripMenuItem,
					this->multilayerNetworkToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(71, 24);
			this->processToolStripMenuItem->Text = L"process";
			// 
			// singleLayerNeuralNetworkToolStripMenuItem
			// 
			this->singleLayerNeuralNetworkToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->perceptronToolStripMenuItem,
					this->deltaToolStripMenuItem, this->multiPerceptronToolStripMenuItem, this->multiDeltaToolStripMenuItem
			});
			this->singleLayerNeuralNetworkToolStripMenuItem->Name = L"singleLayerNeuralNetworkToolStripMenuItem";
			this->singleLayerNeuralNetworkToolStripMenuItem->Size = System::Drawing::Size(261, 26);
			this->singleLayerNeuralNetworkToolStripMenuItem->Text = L"single layer neural network";
			// 
			// perceptronToolStripMenuItem
			// 
			this->perceptronToolStripMenuItem->Name = L"perceptronToolStripMenuItem";
			this->perceptronToolStripMenuItem->Size = System::Drawing::Size(189, 26);
			this->perceptronToolStripMenuItem->Text = L"Perceptron";
			this->perceptronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::perceptronToolStripMenuItem_Click);
			// 
			// deltaToolStripMenuItem
			// 
			this->deltaToolStripMenuItem->Name = L"deltaToolStripMenuItem";
			this->deltaToolStripMenuItem->Size = System::Drawing::Size(189, 26);
			this->deltaToolStripMenuItem->Text = L"Delta";
			this->deltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deltaToolStripMenuItem_Click);
			// 
			// multiPerceptronToolStripMenuItem
			// 
			this->multiPerceptronToolStripMenuItem->Name = L"multiPerceptronToolStripMenuItem";
			this->multiPerceptronToolStripMenuItem->Size = System::Drawing::Size(189, 26);
			this->multiPerceptronToolStripMenuItem->Text = L"MultiPerceptron";
			this->multiPerceptronToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::multiPerceptronToolStripMenuItem_Click);
			// 
			// multiDeltaToolStripMenuItem
			// 
			this->multiDeltaToolStripMenuItem->Name = L"multiDeltaToolStripMenuItem";
			this->multiDeltaToolStripMenuItem->Size = System::Drawing::Size(189, 26);
			this->multiDeltaToolStripMenuItem->Text = L"MultiDelta";
			this->multiDeltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::multiDeltaToolStripMenuItem_Click);
			// 
			// multilayerNetworkToolStripMenuItem
			// 
			this->multilayerNetworkToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->twoLayerToolStripMenuItem,
					this->twoLayerWithMomentToolStripMenuItem
			});
			this->multilayerNetworkToolStripMenuItem->Name = L"multilayerNetworkToolStripMenuItem";
			this->multilayerNetworkToolStripMenuItem->Size = System::Drawing::Size(261, 26);
			this->multilayerNetworkToolStripMenuItem->Text = L"multilayer network";
			// 
			// twoLayerToolStripMenuItem
			// 
			this->twoLayerToolStripMenuItem->Name = L"twoLayerToolStripMenuItem";
			this->twoLayerToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->twoLayerToolStripMenuItem->Text = L"two layer";
			this->twoLayerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::twoLayerToolStripMenuItem_Click);
			// 
			// twoLayerWithMomentToolStripMenuItem
			// 
			this->twoLayerWithMomentToolStripMenuItem->Name = L"twoLayerWithMomentToolStripMenuItem";
			this->twoLayerWithMomentToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->twoLayerWithMomentToolStripMenuItem->Text = L"two layer with moment";
			this->twoLayerWithMomentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::twoLayerWithMomentToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1001, 273);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Cycle: 0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1004, 403);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 40);
			this->button1->TabIndex = 8;
			this->button1->Text = L"CleanUp";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1001, 215);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Weights: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1004, 155);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 38);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Weight Set";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(1004, 65);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(882, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(116, 17);
			this->label3->TabIndex = 12;
			this->label3->Text = L"number of class: ";
			// 
			// comboBox1
			// 
			this->comboBox1->AccessibleDescription = L"";
			this->comboBox1->AccessibleName = L"";
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { 1, 2, 3, 4, 5, 6 });
			this->comboBox1->Location = System::Drawing::Point(1004, 311);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(120, 24);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->Text = L"Select Class";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(1182, 66);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(95, 21);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"MultiLayer";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(1264, 111);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 22);
			this->numericUpDown2->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1138, 113);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 17);
			this->label5->TabIndex = 17;
			this->label5->Text = L"HiddenLayerSize:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1001, 241);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 17);
			this->label4->TabIndex = 18;
			this->label4->Text = L"V weights:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1004, 356);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 41);
			this->button3->TabIndex = 19;
			this->button3->Text = L"sample set (4,6)";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1141, 356);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(136, 41);
			this->button4->TabIndex = 20;
			this->button4->Text = L"sampleSet2 (4,8)";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1437, 871);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip3);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip3->ResumeLayout(false);
			this->menuStrip3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		


private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
	
	
	double label = 0;
	double bias = -1;
	//renk arrayi
	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	//hangi siniftan ornek verilecegini belirleme(select class)
	int selectedIndex = comboBox1->SelectedIndex;
	comboBox1->SelectedItem->ToString();
	int selectedValue = (int)comboBox1->Items[selectedIndex];
	//belirlenen sinif sayisi
	numberof_class = (int)numericUpDown1->Value;
	
	if (numberof_class <= 2)
	{
		Color c;
		if (selectedValue==1)
		{
			Coordinate[index] = e->X - 300;
			index++;
			Coordinate[index] = -(e->Y - 300);
			index++;

			label = 1;
			Coordinate[index] = bias;
			index++;
			Coordinate[index] = label;
			index++;

			
			c = Color::FromArgb(color[0],color[1],color[2]);
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel(e->X + i, e->Y, c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel(e->X, e->Y + i, c);
			}
		}
		if (selectedValue==2)
		{

			Coordinate[index] = e->X - 300;
			index++;
			Coordinate[index] = -(e->Y - 300);
			index++;			

			label = -1;
			Coordinate[index] = bias;
			index++;
			Coordinate[index] = label;
			index++;

			
			c = Color::FromArgb(color[3], color[4], color[5]);
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel(e->X + i, e->Y, c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel(e->X, e->Y + i, c);
			}


		}
		arraySize = index;
	}
	
	else
	{
		
		Color c;

		//etiket degerlerini olusturma
		double *d = new double[numberof_class*numberof_class];
		for (int i = 0; i < numberof_class*numberof_class; i += numberof_class + 1)
		{
			d[i] = 1;
			if (i == numberof_class * numberof_class - 1)
				break;

			for (int j = 1; j <= numberof_class; j++)
			{
				d[i + j] = -1;
			}
		}
		

		Coordinate[index] = e->X - 300;
		index++;
		Coordinate[index] = -(e->Y -300);
		index++;
		
		Coordinate[index] = bias;
		index++;
		//label atamasi
		for (int i = 0; i < numberof_class; i++)
		{
			Coordinate[index] = d[(selectedValue-1)*numberof_class+i];
			index++;
		}

		c = Color::FromArgb(color[3*(selectedValue-1)+0], color[3 * (selectedValue - 1) +1], color[3 * (selectedValue - 1) +2]);
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel(e->X + i, e->Y, c);
		}
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel(e->X, e->Y + i, c);
		}

		arraySize = index;
	}
	
	pictureBox1->Image = surface;
	
	

}




//TEK KATEGORÝLÝ TEK  KATMANLI AYRIK OGRENME
private: System::Void perceptronToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	double *Coordinate_normalize = new double[arraySize];
	Coordinate_normalize = normalize(Coordinate, arraySize, size, numberof_class);
	Color c = Color::FromArgb(255, 255, 255);
	/*pictureBox1->Image = surface;*/

	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j++)
		{
			surface->SetPixel(j, i, c);
		}

		for (int j = 0; j < arraySize; j += 4)
		{
			if (Coordinate_normalize[j + 3] == 1)
				c = Color::FromArgb(color[0], color[1], color[2]);
			else if (Coordinate_normalize[j + 3] == -1)
				c = Color::FromArgb(color[3], color[4], color[5]);
			
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((50* Coordinate_normalize[j] + 300) + i, (-50* Coordinate_normalize[j + 1] + 300), c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((50* Coordinate_normalize[j] + 300), (-50* Coordinate_normalize[j + 1] + 300) + i, c);
			}
		}
		

		array = Perceptron(Coordinate_normalize,W, arraySize, size);
		pictureBox1->Refresh();

		label1->Text = "cycle: " + array[4].ToString();
	
	

	
}



 //TEK KATEGORÝLÝ TEK  KATMANLI SUREKLÝ OGRENME
private: System::Void deltaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	double *Coordinate_normalize = new double[arraySize];
	Coordinate_normalize = normalize(Coordinate, arraySize, size, numberof_class);
	Color c = Color::FromArgb(255, 255, 255);
	/*pictureBox1->Image = surface;*/

	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j++)
		{
			surface->SetPixel(j, i, c);
		}

	for (int j = 0; j < arraySize; j += 4)
	{
		if (Coordinate_normalize[j + 3] == 1)
			c = Color::FromArgb(color[0], color[1], color[2]);
		else if (Coordinate_normalize[j + 3] == -1)
			c = Color::FromArgb(color[3], color[4], color[5]);

		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((50 * Coordinate_normalize[j] + 300) + i, (-50 * Coordinate_normalize[j + 1] + 300), c);
		}
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((50 * Coordinate_normalize[j] + 300), (-50 * Coordinate_normalize[j + 1] + 300) + i, c);
		}
	}


	array = Delta(Coordinate_normalize, W, arraySize, size);
	pictureBox1->Refresh();

	label1->Text = "cycle: " + array[4].ToString();





}

//TEK KATEGORÝLÝ COK  KATMANLI AYRIK OGRENME
private: System::Void multiPerceptronToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
		double *Coordinate_normalize = new double[arraySize];
		Coordinate_normalize = normalize(Coordinate, arraySize, size, numberof_class);

		Color c = Color::FromArgb(255, 255, 255);
		/*pictureBox1->Image = surface;*/
		int selectedValue;

		for (int i = 0; i < pictureBox1->Height; i++)
			for (int j = 0; j < pictureBox1->Width; j++)
			{
				surface->SetPixel(j, i, c);
			}

		for (int j = 0; j < arraySize; j += (3+numberof_class))
		{
			for(int h = 0; h < numberof_class; h++)
			{
				if (Coordinate_normalize[j + 3 + h]==1)
				{
					selectedValue = h + 1;
				}
			}
			c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((50 * Coordinate_normalize[j] + 300) + i, (-50 * Coordinate_normalize[j + 1] + 300), c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((50 * Coordinate_normalize[j] + 300), (-50 * Coordinate_normalize[j + 1] + 300) + i, c);
			}

		}

		array = MultiPerceptron(Coordinate_normalize, W, arraySize, size, numberof_class);
		pictureBox1->Refresh();
		label1->Text = "cycle: " + array[4*numberof_class].ToString();

}


//TEK KATEGORÝLÝ COK KATMANLI SUREKLÝ OGRENME
private: System::Void multiDeltaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	double *Coordinate_normalize = new double[arraySize];
	Coordinate_normalize = normalize(Coordinate, arraySize, size, numberof_class);

	Color c = Color::FromArgb(255, 255, 255);
	/*pictureBox1->Image = surface;*/
	int selectedValue;

	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j++)
		{
			surface->SetPixel(j, i, c);
		}

	for (int j = 0; j < arraySize; j += (3 + numberof_class))
	{
		for (int h = 0; h < numberof_class; h++)
		{
			if (Coordinate_normalize[j + 3 + h] == 1)
			{
				selectedValue = h + 1;
			}
		}
		c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((50 * Coordinate_normalize[j] + 300) + i, (-50 * Coordinate_normalize[j + 1] + 300), c);
		}
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((50 * Coordinate_normalize[j] + 300), (-50 * Coordinate_normalize[j + 1] + 300) + i, c);
		}

	}

	array = MultiDelta(Coordinate_normalize, W, arraySize, size, numberof_class);
	pictureBox1->Refresh();
	label1->Text = "cycle: " + array[4 * numberof_class].ToString();

}


// DOGRULARIN CIZILMESI
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };

	if (numberof_class > 2)
	{
		for (int i = 0; i < numberof_class; i++)
			e->Graphics->DrawLine(gcnew Pen(Color::FromArgb(color[3 * i + 0], color[3 * i + 1], color[3 * i + 2])), Point(array[4 * i + 0], array[4 * i + 1]), Point(array[4 * i + 2], array[4 * i + 3]));
	}
		
	else
	{
		e->Graphics->DrawLine(gcnew Pen(Color::FromArgb(0, 255, 0)), Point(array[0], array[1]), Point(array[2], array[3]));
	}
}


//TEMÝZLEME BUTONU
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numberof_class > 2)
	{
		for (int i = 0; i < 30; i++)
			array[i] = -1;
	}

	else
	{
		for (int i = 0; i < 30; i++)
			array[i] = -1;
		
	}

	Color c1 = Color::FromArgb(255, 255, 255);
	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j++)
		{
			surface->SetPixel(j, i, c1);
		}

	for (int i = 0; i < arraySize; i++)
	{
		Coordinate[i] = -1;
	}
	arraySize = 0;
	index = 0;
	pictureBox1->Refresh();
	
}

//BASLANGIC AGIRLIKLARININ BELÝRLENMESÝ
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox1->Checked == true)
	{
	
		W = random_weight(((int)numericUpDown1->Value)*(((int)numericUpDown2->Value) + 1));
		label2->Text = "Weights: " + W[0].ToString() + " , " + W[1].ToString() + " , " + W[2].ToString() + " , " + W[3].ToString() + "......";
		V = random_weight(((int)numericUpDown2->Value)*size);
		label4->Text = "V weights : " + V[0].ToString() + " , " + V[1].ToString() + " , " + V[2].ToString() + " , " + V[3].ToString() + "......";
	}	
	else
	{
		if (((int)numericUpDown1->Value) > 2)
		{
			W = random_weight(size*((int)numericUpDown1->Value));
			label2->Text = "Weights: " + W[0].ToString() + " , " + W[1].ToString() + " , " + W[2].ToString() + " , " +W[3].ToString() + "......";
		}
		else
		{
			W = random_weight(size);
			label2->Text = "Weights: " + W[0].ToString() + " , " + W[1].ToString() + " , " + W[2].ToString();
		}
	
	}
	

}





private: System::Void twoLayerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	double *Coordinate_normalize = new double[arraySize];
	Coordinate_normalize = normalize(Coordinate, arraySize, size, numberof_class);

	Color c = Color::FromArgb(255, 255, 255);
	int selectedValue;

	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j++)
		{
			surface->SetPixel(j, i, c);
		}
/*
	for (int j = 0; j < arraySize; j += (3 + numberof_class))
	{
		for (int h = 0; h < numberof_class; h++)
		{
			if (Coordinate_normalize[j + 3 + h] == 1)
			{
				selectedValue = h + 1;
			}
		}
		c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((50 * Coordinate_normalize[j] + 300) + i, (-50 * Coordinate_normalize[j + 1] + 300), c);
		}
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((50 * Coordinate_normalize[j] + 300), (-50 * Coordinate_normalize[j + 1] + 300) + i, c);
		}
	}*/
	double a[16] = { 0,0,-1,-1  ,0,1,-1,1,  1,1,-1,-1,   1,0,-1,1 };
	double WW[3] = { 0.164732,0.752621,-0.993423 };
	double VV[6] = { 0.129952,0.570345,0.341332,-0.923123,0.328932,-0.115223};
	int cycle=MultilayerNetwork(Coordinate_normalize, W, V, arraySize, size,numberof_class, ((int)numericUpDown2->Value));
	

	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j+=2)
		{
			double temp[3] = { i-300,-(j-300),-1 };
			int result = MultiLayerNetworkResultView(temp, W, V, size, numberof_class, ((int)numericUpDown2->Value));
			if (result==0)
				surface->SetPixel(i, j, Color::FromArgb(255, 138, 31));
			else if(result==1)
				surface->SetPixel(i, j, Color::FromArgb(170, 230, 255));
			else if(result==2)
				surface->SetPixel(i, j, Color::FromArgb(170, 255, 228));
			else if (result == 3)
				surface->SetPixel(i, j, Color::FromArgb(100, 100, 100));
			else if (result == 4)
				surface->SetPixel(i, j, Color::FromArgb(255, 70, 255));
			else
			{
				surface->SetPixel(i, j, Color::FromArgb(70, 255, 255));
			}
		
		}

	if (numberof_class > 2)
	{
		for (int j = 0; j < arraySize; j += (3 + numberof_class))
		{
			for (int h = 0; h < numberof_class; h++)
			{
				if (Coordinate[j + 3 + h] == 1)
				{
					selectedValue = h + 1;
				}
			}
			c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300) + i, -(Coordinate[j + 1]) + 300, c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300), -(Coordinate[j + 1]) + 300 + i, c);
			}

		}
	} 
	
	else
	{
		for (int j = 0; j < arraySize; j +=4)
		{
			
			if (Coordinate[j+3] == 1)
				c = Color::FromArgb(255, 0, 0);
			else
				c = Color::FromArgb(0, 0, 255);
			
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300) + i, -(Coordinate[j + 1]) + 300, c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300), -(Coordinate[j + 1]) + 300 + i, c);
			}

		}
	}
	

	

	pictureBox1->Refresh();
	label1->Text = "cycle: " + cycle.ToString();


}
private: System::Void twoLayerWithMomentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	double *Coordinate_normalize = new double[arraySize];
	Coordinate_normalize = normalize(Coordinate, arraySize, size, numberof_class);

	Color c = Color::FromArgb(255, 255, 255);
	int selectedValue;

	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j++)
		{
			surface->SetPixel(j, i, c);
		}
	/*
	for (int j = 0; j < arraySize; j += (3 + numberof_class))
	{
	for (int h = 0; h < numberof_class; h++)
	{
	if (Coordinate_normalize[j + 3 + h] == 1)
	{
	selectedValue = h + 1;
	}
	}
	c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
	for (int i = -2; i <= 2; i++)
	{
	surface->SetPixel((50 * Coordinate_normalize[j] + 300) + i, (-50 * Coordinate_normalize[j + 1] + 300), c);
	}
	for (int i = -2; i <= 2; i++)
	{
	surface->SetPixel((50 * Coordinate_normalize[j] + 300), (-50 * Coordinate_normalize[j + 1] + 300) + i, c);
	}
	}*/
	//double a[16] = { 0,0,-1,-1  ,0,1,-1,1,  1,1,-1,-1,   1,0,-1,1 };
	//double WW[3] = { 0.164732,0.752621,-0.993423 };
	//double VV[6] = { 0.129952,0.570345,0.341332,-0.923123,0.328932,-0.115223 };
	int cycle = MultilayerNetworkMoment(Coordinate_normalize, W, V, arraySize, size, numberof_class, ((int)numericUpDown2->Value));


	for (int i = 0; i < pictureBox1->Height; i++)
		for (int j = 0; j < pictureBox1->Width; j += 2)
		{
			double temp[3] = { i - 300,-(j - 300),-1 };
			int result = MultiLayerNetworkResultView(temp, W, V, size, numberof_class, ((int)numericUpDown2->Value));
			if (result == 0)
				surface->SetPixel(i, j, Color::FromArgb(255, 138, 31));
			else if (result == 1)
				surface->SetPixel(i, j, Color::FromArgb(170, 230, 255));
			else if (result == 2)
				surface->SetPixel(i, j, Color::FromArgb(170, 255, 228));
			else if (result == 3)
				surface->SetPixel(i, j, Color::FromArgb(100, 100, 100));
			else if (result == 4)
				surface->SetPixel(i, j, Color::FromArgb(255, 70, 255));
			else
			{
				surface->SetPixel(i, j, Color::FromArgb(70, 255, 255));
			}

		}

	if (numberof_class > 2)
	{
		for (int j = 0; j < arraySize; j += (3 + numberof_class))
		{
			for (int h = 0; h < numberof_class; h++)
			{
				if (Coordinate[j + 3 + h] == 1)
				{
					selectedValue = h + 1;
				}
			}
			c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300) + i, -(Coordinate[j + 1]) + 300, c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300), -(Coordinate[j + 1]) + 300 + i, c);
			}

		}
	}

	else
	{
		for (int j = 0; j < arraySize; j += 4)
		{

			if (Coordinate[j + 3] == 1)
				c = Color::FromArgb(255, 0, 0);
			else
				c = Color::FromArgb(0, 0, 255);

			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300) + i, -(Coordinate[j + 1]) + 300, c);
			}
			for (int i = -2; i <= 2; i++)
			{
				surface->SetPixel((Coordinate[j] + 300), -(Coordinate[j + 1]) + 300 + i, c);
			}

		}
	}


	pictureBox1->Refresh();
	label1->Text = "cycle: " + cycle.ToString();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	double ornek1[126] = { -150,180,-1,1,-1,-1,-1,104,-99,-1,1,-1,-1,-1,132,170,-1,-1,1,-1,-1,-229,38,-1,-1,-1,1,-1,-101,-196,-1,-1,-1,-1,1,
					  -133,212,-1,1,-1,-1,-1,134,104,-1,-1,1,-1,-1,-189,28,-1,-1,-1,1,-1,87,-252,-1,-1,1,-1,-1,133,-209,-1,-1,1,-1,-1,
					  171,-26,-1,1,-1,-1,-1,131,-54,-1,1,-1,-1,-1,-47,-96,-1,-1,-1,-1,1,-68,-135,-1,-1,-1,-1,1,-25,-31,-1,-1,-1,-1,1,
						-9,5,-1,-1,-1,-1,1, 26,32,-1,-1,-1,-1,1, 52,47,-1,-1,-1,-1,1 };
	//4 sýnýf 8 hiddenlayerSize icin hazýr ornek
	double ornekW[28] = { -0.943078380335884 , -5.06005450250439 , -2.55972671557118 , 2.37242662789438 , 5.39803620866229 , -0.482692818420523 , 0.0216409670974772 , 1.21482817513194 , 3.64910081395325 , -0.0678563180669522 , 2.3828420368185 , -0.767641121679481 , -2.79882025580662 , -2.10003036405702 , 1.36596188937779 , 1.03765021293022 , 1.06929408526 , 0.441612917901756 , -3.35330422189618 , 0.844826928969774 , -3.32150361934626 , -0.158444200898988 , -1.26821475391142 , 3.20289109147215 , -4.47752499654229 , 2.64867403784338 , 5.07115940904995 , -2.1100806001799 };
	double ornekV[18] = { 0.822026775075502 , 1.08790636902072 , 1.95195054737468 , -1.12189404298392 , 2.87197514478894 , 0.107294221566708 , 2.02027828689976 , -1.53587424243537 , -2.11689991132337 , -2.30550094307031 , 2.03100361328201 , 2.39625688041076 , 2.2381846512283 , 3.01515239884387 , -0.62160860928369 , -2.46859954155922 , 0.57267972192881 , -0.825534924115878 };

	for (int i = 0; i < 126; i++)
	{
		Coordinate[index] = ornek1[i];
		index++;
	}
	arraySize = index;


	for (int i = 0; i < 28;i++)
		W[i] = ornekW[i];
	label2->Text = "Weights: " + W[0].ToString() + " , " + W[1].ToString() + " , " + W[2].ToString() + " , " + W[3].ToString() + "......";

	for (int i = 0; i < 18;i++)
		V[i] = ornekV[i];
	label4->Text = "V weights : " + V[0].ToString() + " , " + V[1].ToString() + " , " + V[2].ToString() + " , " + V[3].ToString() + "......";

	
	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	Color c = Color::FromArgb(255, 255, 255);
	int selectedValue;
	numberof_class = 4;
	
	for (int j = 0; j < arraySize; j += (3 + numberof_class))
	{
		for (int h = 0; h < numberof_class; h++)
		{
			if (Coordinate[j + 3 + h] == 1)
			{
				selectedValue = h + 1;
			}
		}
		c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((Coordinate[j] + 300) + i, -(Coordinate[j + 1]) + 300, c);
		}
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((Coordinate[j] + 300), -(Coordinate[j + 1]) + 300 + i, c);
		}

	}
	pictureBox1->Refresh();

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	double ornek1[84] = { -144,160,-1,1,-1,-1,-1,-31,42,-1,1,-1,-1,-1,88,-65,-1,1,-1,-1,-1,161,148,-1,-1,1,-1,-1,-247,-14,-1,-1,-1,1,-1,-164,-16,-1,-1,-1,1,-1,-221,-124,-1,-1,-1,1,-1,-72,257,-1,-1,-1,-1,1,26,247,-1,-1,-1,-1,1,230,214,-1,-1,-1,-1,1,157,94,-1,-1,1,-1,-1,15,-198,-1,-1,1,-1,-1, };
	//4 sýnýf 8 hiddenlayerSize icin hazýr ornek
	double ornekW[36] = { 1.49079892342361,0.483233686607991,0.69726440991217,-2.70666924279767,-2.58969569782992,-0.115060408448734,1.44625959646849,3.34371543742361,1.78509922863561,0.613118043851996,-0.89094630091767,-3.5207420515516,-0.608522570365089,3.27687140670911,2.97751498059016,0.436625837141226,-3.11035133624496,2.95649687905298,-0.141861903858558,0.496126794439792,0.214388170956983,-0.444243302195568,-0.334914413695913,-1.79233659987093,0.773987718845013,-2.74226055420123,1.16075420988337,1.20036477228937,2.75035665075099,1.09021888130579,3.02099190240466,2.34891309393653,-0.401864763224343,0.333540240434482,0.668284532857769,-0.850025579735191 };
	double ornekV[24] = { -0.705125623189528,1.43114435138924,1.07923067024438,-0.444987458140922,-0.0337761913969272,1.39938864096738,0.502542798304964,1.80668956522536,2.08752676198112,0.510640950050613,2.41867800082468,2.49822928459848,1.6558243925476,2.06575444585583,0.771389368467001,1.8612646821185,-0.642393062681864,-0.130982623327601,-0.039706922144694,0.125794709090533,1.39711433281538,1.68461571487222,1.26184242766385,-1.36548631156767 };

	for (int i = 0; i < 84; i++)
	{
		Coordinate[index] = ornek1[i];
		index++;
	}
	arraySize = index;


	for (int i = 0; i < 36;i++)
		W[i] = ornekW[i];
	label2->Text = "Weights: " + W[0].ToString() + " , " + W[1].ToString() + " , " + W[2].ToString() + " , " + W[3].ToString() + "......";

	for (int i = 0; i < 24;i++)
		V[i] = ornekV[i];
	label4->Text = "V weights : " + V[0].ToString() + " , " + V[1].ToString() + " , " + V[2].ToString() + " , " + V[3].ToString() + "......";


	int color[18] = { 255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 0, 0, 255, 0, 255, 0, 255, 255 };
	Color c = Color::FromArgb(255, 255, 255);
	int selectedValue;
	numberof_class = 4;

	for (int j = 0; j < arraySize; j += (3 + numberof_class))
	{
		for (int h = 0; h < numberof_class; h++)
		{
			if (Coordinate[j + 3 + h] == 1)
			{
				selectedValue = h + 1;
			}
		}
		c = Color::FromArgb(color[3 * (selectedValue - 1) + 0], color[3 * (selectedValue - 1) + 1], color[3 * (selectedValue - 1) + 2]);
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((Coordinate[j] + 300) + i, -(Coordinate[j + 1]) + 300, c);
		}
		for (int i = -2; i <= 2; i++)
		{
			surface->SetPixel((Coordinate[j] + 300), -(Coordinate[j + 1]) + 300 + i, c);
		}

	}
	pictureBox1->Refresh();
}
};


}
