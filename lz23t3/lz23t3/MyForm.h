#pragma once

namespace lz23t3 {

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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(151, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1117, 472);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->ForeColor = System::Drawing::Color::IndianRed;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 42;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Добрий день", L"Привіт", L"Ранок", L"Добрий ранок",
					L"День", L"Доброго ранку", L"Вечір", L"Доброго вечора"
			});
			this->listBox1->Location = System::Drawing::Point(151, 502);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(410, 340);
			this->listBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Bisque;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Chocolate;
			this->button1->Location = System::Drawing::Point(736, 577);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(517, 183);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1516, 964);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Перевіряємо, чи вибрано слово у списку
		if (listBox1->SelectedIndex == -1) {
			MessageBox::Show("Будь ласка, виберіть слово зі списку!");
			return;
		}

		String^ path = "";

		// 2. Прив'язуємо індекс вибраного слова до назви вашого аудіофайлу
		switch (listBox1->SelectedIndex) {
		case 0: path = "Hello.wav"; break; // Добрий день
		case 1: path = "Hi.wav"; break;    // Привіт
		case 2: path = "Morning.wav"; break; // Ранок
		case 3: path = "G_m.wav"; break;   // Добрий ранок
		case 4: path = "a.wav"; break;     // День (Afternoon)
		case 5: path = "g_a.wav"; break;   // Доброго дня (Good afternoon)
		case 6: path = "ev.wav"; break;    // Вечір (Evening)
		case 7: path = "g_e.wav"; break;   // Доброго вечора (Good evening)
		}

		// 3. Відтворюємо звук
		if (path != "") {
			try {
				System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer(path);
				player->Load();
				player->Play();
			}
			catch (...) {
				MessageBox::Show("Не вдалося знайти файл: " + path + ". Перевірте, чи він лежить у папці Debug.");
			}
		}
	}
};
}
