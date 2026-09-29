#pragma once

namespace lab23t1 {

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
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Лінія", L"Прямокутник", L"Зафарбований прмяокутник",
					L"Еліпс", L"Зафарбований еліпс ", L"Сектор", L"Зірка", L"Трикутник", L"Будиночок"
			});
			this->listBox1->Location = System::Drawing::Point(820, 91);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(524, 324);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Red", L"Green", L"Blue", L"Yellow" });
			this->comboBox1->Location = System::Drawing::Point(839, 460);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(452, 28);
			this->comboBox1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1533, 869);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graf = CreateGraphics();
		

		Color selectedColor = Color::Black;

		
		if (comboBox1->SelectedIndex == 0) selectedColor = Color::Red;
		else if (comboBox1->SelectedIndex == 1) selectedColor = Color::Green;
		else if (comboBox1->SelectedIndex == 2) selectedColor = Color::Blue;
		else if (comboBox1->SelectedIndex == 3) selectedColor = Color::Yellow;

		
		Pen^ customPen = gcnew System::Drawing::Pen(selectedColor, 5);
		Brush^ customBrush = gcnew System::Drawing::SolidBrush(selectedColor);

		
		Pen^ thickPen = gcnew System::Drawing::Pen(selectedColor, 8);

		graf->Clear(Color::White); // Очищаємо фон

		// 3. Малюємо фігуру залежно від вибору в ListBox1
		switch (listBox1->SelectedIndex) {
		case 0: // Лінія
			graf->DrawLine(thickPen, 50, 40, 250, 160);
			break;
		case 1: // Прямокутник
			graf->DrawRectangle(customPen, 40, 40, 150, 80);
			break;
		case 2: // Зафарбований прямокутник
			graf->FillRectangle(customBrush, 40, 40, 150, 80);
			break;
		case 3: // Еліпс
			graf->DrawEllipse(customPen, 40, 40, 200, 140);
			break;
		case 4: // Зафарбований еліпс
			graf->FillEllipse(customBrush, 40, 40, 200, 140);
			break;
		case 5: // Сектор
			graf->FillPie(customBrush, 40, 40, 200, 200, 180, 90);
			break;
		case 6: { // Зірка
			cli::array<Point>^ starPoints = gcnew cli::array<Point>{
				Point(120, 30), Point(145, 100), Point(215, 100),
					Point(155, 150), Point(180, 230), Point(120, 180),
					Point(60, 230), Point(85, 150), Point(25, 100), Point(95, 100)
			};
			graf->FillPolygon(customBrush, starPoints);
			graf->DrawPolygon(customPen, starPoints);
			break;
		}
		case 7: {
			cli::array<Point>^ trianglePoints = gcnew cli::array<Point>{
				Point(150, 50),   // Верхня вершина
					Point(50, 200),   // Ліва нижня вершина
					Point(250, 200)   // Права нижня вершина
			};
			graf->FillPolygon(customBrush, trianglePoints);
			graf->DrawPolygon(customPen, trianglePoints);
			break;
		}
		case 8: { 
			graf->FillRectangle(customBrush, 100, 100, 150, 150);
			graf->DrawRectangle(Pens::Black, 100, 100, 150, 150); // Контур стін

			// Дах (фіксований червоний колір, щоб виглядало як дах)
			cli::array<Point>^ roof = gcnew cli::array<Point>{
				Point(75, 100),   // лівий край
					Point(175, 20),   // вершина
					Point(275, 100)   // правий край
			};
			graf->FillPolygon(Brushes::Red, roof);
			graf->DrawPolygon(Pens::Black, roof);

			// Двері (фіксований коричневий колір)
			graf->FillRectangle(Brushes::Brown, 140, 160, 50, 90);
			graf->DrawRectangle(Pens::Black, 140, 160, 50, 90);
			break;
		}
		}
	}
	
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	// Встановлюємо першим обраним елементом перший колір зі списку (індекс 0)
	if (comboBox1->Items->Count > 0) {
		comboBox1->SelectedIndex = 0;
	}
}
};
}
