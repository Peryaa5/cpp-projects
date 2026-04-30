#include <Windows.h>
int NODtwo(int a, int b) {//алгоритм Евклида для двух значений
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int NODandNOK(int* array, int n, int flag) {//вычисление НОД и НОК
	int nod = abs(array[0]);
	int nok = abs(array[0]);
	for (int i = 1; i < n; i++) {
		nod = NODtwo(nod, abs(array[i]));
		nok = (nok / NODtwo(nok, abs(array[i])) * abs(array[i]));
	}
	if (flag == 1) return nod;
	else return nok;
}
namespace КурсоваяНОДиНОК {

	//подключение пространств
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// Сводка для MyForm
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:MyForm(void) {
		InitializeComponent();// Инициализация компонентов
	}
	protected:~MyForm() {
		if (components) delete components;// Освободить все используемые ресурсы
	}


	//необходимые переменные для работы программы
	private: int flag = 0;
	private: int n = 0;
	private: int* array = new int[n];
	bool isMouseDown = false;
	int xOffset, yOffset;
	int messflag = 0;


	//элементы
	private: System::Windows::Forms::Label^ label_nok;
	private: System::Windows::Forms::Label^ label_now;
	private: System::Windows::Forms::Label^ label_message;
	private: System::Windows::Forms::Button^ button_ready;
	private: System::Windows::Forms::TextBox^ vvod;
	private: System::Windows::Forms::Label^ label_nod;
	private: System::Windows::Forms::Button^ button_clear;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;


	/// Обязательная переменная конструктора.
	private:System::ComponentModel::Container^ components;


	//Дизайн
	void InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		this->label_nok = (gcnew System::Windows::Forms::Label());
		this->label_now = (gcnew System::Windows::Forms::Label());
		this->label_message = (gcnew System::Windows::Forms::Label());
		this->button_ready = (gcnew System::Windows::Forms::Button());
		this->vvod = (gcnew System::Windows::Forms::TextBox());
		this->label_nod = (gcnew System::Windows::Forms::Label());
		this->button_clear = (gcnew System::Windows::Forms::Button());
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->button_exit = (gcnew System::Windows::Forms::Button());
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->panel2 = (gcnew System::Windows::Forms::Panel());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
		this->SuspendLayout();
		// 
		// label_nok
		// 
		this->label_nok->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 21.85714F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_nok->ForeColor = System::Drawing::Color::AntiqueWhite;
		this->label_nok->Location = System::Drawing::Point(388, 408);
		this->label_nok->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->label_nok->Name = L"label_nok";
		this->label_nok->Size = System::Drawing::Size(650, 60);
		this->label_nok->TabIndex = 1;
		this->label_nok->Text = L"НОК: ";
		// 
		// label_now
		// 
		this->label_now->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 20.14286F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_now->ForeColor = System::Drawing::Color::PowderBlue;
		this->label_now->Location = System::Drawing::Point(40, 238);
		this->label_now->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->label_now->Name = L"label_now";
		this->label_now->Size = System::Drawing::Size(945, 76);
		this->label_now->TabIndex = 3;
		this->label_now->Text = L"Изначальный массив c числами: {}";
		// 
		// label_message
		// 
		this->label_message->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_message->ForeColor = System::Drawing::Color::LightSteelBlue;
		this->label_message->Location = System::Drawing::Point(26, 71);
		this->label_message->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->label_message->Name = L"label_message";
		this->label_message->Size = System::Drawing::Size(1012, 65);
		this->label_message->TabIndex = 4;
		this->label_message->Text = L"Введите колличество чисел";
		// 
		// button_ready
		// 
		this->button_ready->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->button_ready->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 15.85714F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button_ready->ForeColor = System::Drawing::Color::MediumTurquoise;
		this->button_ready->Location = System::Drawing::Point(874, 155);
		this->button_ready->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->button_ready->Name = L"button_ready";
		this->button_ready->Size = System::Drawing::Size(124, 59);
		this->button_ready->TabIndex = 5;
		this->button_ready->Text = L"Готово";
		this->button_ready->UseVisualStyleBackColor = true;
		this->button_ready->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
		// 
		// vvod
		// 
		this->vvod->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->vvod->Location = System::Drawing::Point(36, 155);
		this->vvod->Multiline = true;
		this->vvod->Name = L"vvod";
		this->vvod->Size = System::Drawing::Size(796, 59);
		this->vvod->TabIndex = 6;
		this->vvod->TextChanged += gcnew System::EventHandler(this, &MyForm::vvod_TextChanged);
		this->vvod->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::vvod_KeyUp);
		// 
		// label_nod
		// 
		this->label_nod->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 21.85714F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_nod->ForeColor = System::Drawing::Color::LavenderBlush;
		this->label_nod->Location = System::Drawing::Point(388, 333);
		this->label_nod->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->label_nod->Name = L"label_nod";
		this->label_nod->Size = System::Drawing::Size(664, 75);
		this->label_nod->TabIndex = 7;
		this->label_nod->Text = L"НОД: ";
		// 
		// button_clear
		//
		this->button_clear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->button_clear->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 15.85714F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button_clear->ForeColor = System::Drawing::Color::Tan;
		this->button_clear->Location = System::Drawing::Point(763, 542);
		this->button_clear->Name = L"button_clear";
		this->button_clear->Size = System::Drawing::Size(275, 64);
		this->button_clear->TabIndex = 8;
		this->button_clear->Text = L"Очистить ";
		this->button_clear->UseVisualStyleBackColor = true;
		this->button_clear->Click += gcnew System::EventHandler(this, &MyForm::button_Clear);
		// 
		// pictureBox1
		// 
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
		this->pictureBox1->Location = System::Drawing::Point(34, 317);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(335, 301);
		this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->pictureBox1->TabIndex = 9;
		this->pictureBox1->TabStop = false;
		// 
		// button_exit
		// 
		this->button_exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
			static_cast<System::Int32>(static_cast<System::Byte>(45)));
		this->button_exit->FlatAppearance->BorderColor = System::Drawing::Color::RosyBrown;
		this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->button_exit->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button_exit->ForeColor = System::Drawing::Color::IndianRed;
		this->button_exit->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
		this->button_exit->Location = System::Drawing::Point(969, 22);
		this->button_exit->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->button_exit->Name = L"button_exit";
		this->button_exit->Size = System::Drawing::Size(83, 46);
		this->button_exit->TabIndex = 0;
		this->button_exit->Text = L"✖";
		this->button_exit->UseVisualStyleBackColor = false;
		this->button_exit->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
		// 
		// panel1
		// 
		this->panel1->BackColor = System::Drawing::Color::White;
		this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
		this->panel1->Location = System::Drawing::Point(0, 0);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(1063, 10);
		this->panel1->TabIndex = 12;
		// 
		// panel2
		// 
		this->panel2->BackColor = System::Drawing::Color::White;
		this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
		this->panel2->Location = System::Drawing::Point(0, 636);
		this->panel2->Name = L"panel2";
		this->panel2->Size = System::Drawing::Size(1063, 10);
		this->panel2->TabIndex = 13;
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(168, 168);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
			static_cast<System::Int32>(static_cast<System::Byte>(45)));
		this->ClientSize = System::Drawing::Size(1063, 646);
		this->Controls->Add(this->panel2);
		this->Controls->Add(this->panel1);
		this->Controls->Add(this->button_exit);
		this->Controls->Add(this->pictureBox1);
		this->Controls->Add(this->button_clear);
		this->Controls->Add(this->label_nod);
		this->Controls->Add(this->vvod);
		this->Controls->Add(this->button_ready);
		this->Controls->Add(this->label_message);
		this->Controls->Add(this->label_now);
		this->Controls->Add(this->label_nok);
		this->Cursor = System::Windows::Forms::Cursors::Arrow;
		this->Font = (gcnew System::Drawing::Font(L"Haettenschweiler", 8.142858F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->Name = L"MyForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Матрица";
		this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
		this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
		this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}


	//pragma endregion
	private: System::Void vvod_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_Clear(System::Object^ sender, System::EventArgs^ e) {
		Clear();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Base();
	}
	private: System::Void vvod_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			Base();
		};
	}


	//функции с элементами
	private: System::Void Clear() {//очистка формы
		this->label_now->Text = L"Изначальный массив с числами: {}";
		this->label_message->Text = L"Введите колличество чисел";
		this->label_nod->Text = L"НОД: ";
		this->label_nok->Text = L"НОК: ";
		vvod->Text = "";
		flag = 0;
		messflag = 0;
	}
	private: System::Void Base() {
		flag += 1;
		if (flag == 1) {
			try {//Ввод размера масива и проверка правильности ввода
				n = Convert::ToInt32(vvod->Text);
				if (n <= 0) {
					Clear();
					this->label_message->Text = L"Неверный ввод! Введите колличество чисел заново!";
				}
				else this->label_message->Text = L"Введите число номер 1";
			}
			catch (FormatException^) {
				Clear();
				this->label_message->Text = L"Неверный ввод! Введите колличество чисел заново!";

			}


		}
		else {
			if (flag <= n + 1) {//Заполнение массива и проверка правильности ввода
				this->label_message->Text = L"Введите число номер " + (flag);
				try {
					array[flag - 2] = Convert::ToInt32(vvod->Text);
					if (array[flag - 2] < 0 && messflag == 0) {
						messflag = 1;
						MessageBox::Show(L"НОК — это натуральное число, меньше нуля оно быть не может. Поэтому НОК берется от модулей чисел", L"Обрати Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
				}
				catch (FormatException^) {
					Clear();
					this->label_message->Text = L"Неверный ввод! Введите колличество чисел заново!";
				}
				this->label_now->Text = L"Изначальный массив с числами:{ ";
				for (int i = 0; i < flag - 1; i++) {
					this->label_now->Text += array[i] + L" ";
				}
				this->label_now->Text += L"}";
			}

		}
		if (flag == n + 1) {// вывод результата
			this->label_nod->Text += NODandNOK(array, n,1);
			this->label_message->Text = L"Ваш резултат!";
			this->label_nok->Text += NODandNOK(array, n,0);
		}
		vvod->Text = "";
	}
	//перемещение формы
	private: Point mouseOffset;
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == Windows::Forms::MouseButtons::Left)
		{
			if (e->Button == Windows::Forms::MouseButtons::Left)
			{
				xOffset = -e->X - SystemInformation::FrameBorderSize.Width;
				yOffset = -e->Y - SystemInformation::FrameBorderSize.Height;
				mouseOffset = System::Drawing::Point(xOffset, yOffset);
				isMouseDown = true;
			}
		}
	}
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isMouseDown)
		{
			Point mousePos = Control::MousePosition;
			mousePos.Offset(mouseOffset.X, mouseOffset.Y);
			Location = mousePos;
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == Windows::Forms::MouseButtons::Left)
		{
			isMouseDown = false;
		}
	}

};
}
 
