#pragma once

namespace saper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int size; // размер поля
		int mines; // кол-во мин
		array<Button^, 2>^ buttons; // кнопки
		array<bool, 2>^ mine; // мины
		array<int, 2>^ nums; // цифры
		array<bool, 2>^ opened; // открытые клетки
		array<bool, 2>^ flags; // флаги
		int flagcount; // флаги
		Image^ flagimg; // флаг
		Image^ mineimg; // мина
		bool isGameOver; // конец игры
		enum class diff { easy, medium, hard }; // сложность
		diff nowdiff; // текущая сложность
		int sec; // время
	public:
		MyForm(void)
		{
			InitializeComponent();
			size = 0;
			mines = 0;
			sec = 0;
			flagcount = 0;
			buttons = nullptr;
			mine = nullptr;
			nums = nullptr;
			opened = nullptr;
			flags = nullptr;
			flagimg = nullptr;
			mineimg = nullptr;
			isGameOver = false;
			nowdiff = diff::easy;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Button^ easybtn;
	private: System::Windows::Forms::Button^ mediumbtn;
	private: System::Windows::Forms::Button^ hardbtn;
	private: System::Windows::Forms::Button^ helpbtn;
	private: System::Windows::Forms::Button^ exitbtn;
	private: System::Windows::Forms::Label^ flagslabel;
	private: System::Windows::Forms::Label^ timelabel;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::MenuStrip^ menu;
	private: System::Windows::Forms::ToolStripMenuItem^ game;
	private: System::Windows::Forms::ToolStripMenuItem^ newgame;
	private: System::Windows::Forms::ToolStripMenuItem^ mainmenu;
	private: System::Windows::Forms::ToolStripMenuItem^ diffmenu;
	private: System::Windows::Forms::ToolStripMenuItem^ easy;
	private: System::Windows::Forms::ToolStripMenuItem^ medium;
	private: System::Windows::Forms::ToolStripMenuItem^ hard;
	private: System::Windows::Forms::ToolStripMenuItem^ help;
	private: System::Windows::Forms::ToolStripMenuItem^ exit;


	private: System::ComponentModel::IContainer^ components;

	protected:




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->title = (gcnew System::Windows::Forms::Label());
			this->easybtn = (gcnew System::Windows::Forms::Button());
			this->mediumbtn = (gcnew System::Windows::Forms::Button());
			this->hardbtn = (gcnew System::Windows::Forms::Button());
			this->helpbtn = (gcnew System::Windows::Forms::Button());
			this->exitbtn = (gcnew System::Windows::Forms::Button());
			this->flagslabel = (gcnew System::Windows::Forms::Label());
			this->timelabel = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->game = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newgame = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainmenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diffmenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->easy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medium = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hard = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->title->Location = System::Drawing::Point(80, 20);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(100, 30);
			this->title->TabIndex = 0;
			this->title->Text = L"Сапёр";
			this->title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// easybtn
			// 
			this->easybtn->Location = System::Drawing::Point(80, 60);
			this->easybtn->Name = L"easybtn";
			this->easybtn->Size = System::Drawing::Size(100, 30);
			this->easybtn->TabIndex = 1;
			this->easybtn->Text = L"Лёгкий";
			this->easybtn->UseVisualStyleBackColor = true;
			this->easybtn->Click += gcnew System::EventHandler(this, &MyForm::easybtn_Click);
			// 
			// mediumbtn
			// 
			this->mediumbtn->Location = System::Drawing::Point(80, 100);
			this->mediumbtn->Name = L"mediumbtn";
			this->mediumbtn->Size = System::Drawing::Size(100, 30);
			this->mediumbtn->TabIndex = 2;
			this->mediumbtn->Text = L"Средний";
			this->mediumbtn->UseVisualStyleBackColor = true;
			this->mediumbtn->Click += gcnew System::EventHandler(this, &MyForm::mediumbtn_Click);
			// 
			// hardbtn
			// 
			this->hardbtn->Location = System::Drawing::Point(80, 140);
			this->hardbtn->Name = L"hardbtn";
			this->hardbtn->Size = System::Drawing::Size(100, 30);
			this->hardbtn->TabIndex = 3;
			this->hardbtn->Text = L"Сложный";
			this->hardbtn->UseVisualStyleBackColor = true;
			this->hardbtn->Click += gcnew System::EventHandler(this, &MyForm::hardbtn_Click);
			// 
			// helpbtn
			// 
			this->helpbtn->Location = System::Drawing::Point(80, 180);
			this->helpbtn->Name = L"helpbtn";
			this->helpbtn->Size = System::Drawing::Size(100, 30);
			this->helpbtn->TabIndex = 7;
			this->helpbtn->Text = L"Руководство";
			this->helpbtn->UseVisualStyleBackColor = true;
			this->helpbtn->Click += gcnew System::EventHandler(this, &MyForm::helpbtn_Click);
			// 
			// exitbtn
			// 
			this->exitbtn->Location = System::Drawing::Point(80, 220);
			this->exitbtn->Name = L"exitbtn";
			this->exitbtn->Size = System::Drawing::Size(100, 30);
			this->exitbtn->TabIndex = 8;
			this->exitbtn->Text = L"Выход";
			this->exitbtn->UseVisualStyleBackColor = true;
			this->exitbtn->Click += gcnew System::EventHandler(this, &MyForm::exitbtn_Click);
			// 
			// flagslabel
			// 
			this->flagslabel->Location = System::Drawing::Point(10, 30);
			this->flagslabel->Name = L"flagslabel";
			this->flagslabel->Size = System::Drawing::Size(100, 30);
			this->flagslabel->TabIndex = 4;
			this->flagslabel->Text = L"Flags: 0";
			this->flagslabel->Visible = false;
			// 
			// timelabel
			// 
			this->timelabel->Location = System::Drawing::Point(120, 30);
			this->timelabel->Name = L"timelabel";
			this->timelabel->Size = System::Drawing::Size(100, 30);
			this->timelabel->TabIndex = 5;
			this->timelabel->Text = L"Time: 0";
			this->timelabel->Visible = false;
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// menu
			// 
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->game });
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(244, 24);
			this->menu->TabIndex = 6;
			this->menu->Text = L"menuStrip1";
			this->menu->Visible = false;
			// 
			// game
			// 
			this->game->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->newgame, this->mainmenu,
					this->diffmenu, this->help, this->exit
			});
			this->game->Name = L"game";
			this->game->Size = System::Drawing::Size(46, 20);
			this->game->Text = L"Игра";
			// 
			// newgame
			// 
			this->newgame->Name = L"newgame";
			this->newgame->Size = System::Drawing::Size(221, 22);
			this->newgame->Text = L"Новая игра";
			this->newgame->Click += gcnew System::EventHandler(this, &MyForm::newgame_Click);
			// 
			// mainmenu
			// 
			this->mainmenu->Name = L"mainmenu";
			this->mainmenu->Size = System::Drawing::Size(221, 22);
			this->mainmenu->Text = L"Вернуться в главное меню";
			this->mainmenu->Click += gcnew System::EventHandler(this, &MyForm::mainmenu_Click);
			// 
			// diffmenu
			// 
			this->diffmenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->easy, this->medium,
					this->hard
			});
			this->diffmenu->Name = L"diffmenu";
			this->diffmenu->Size = System::Drawing::Size(221, 22);
			this->diffmenu->Text = L"Сложность";
			// 
			// easy
			// 
			this->easy->Name = L"easy";
			this->easy->Size = System::Drawing::Size(213, 22);
			this->easy->Text = L"Лёгкий (8x8, 10 мин)";
			this->easy->Click += gcnew System::EventHandler(this, &MyForm::easy_Click);
			// 
			// medium
			// 
			this->medium->Name = L"medium";
			this->medium->Size = System::Drawing::Size(213, 22);
			this->medium->Text = L"Средний (16x16, 40 мин)";
			this->medium->Click += gcnew System::EventHandler(this, &MyForm::medium_Click);
			// 
			// hard
			// 
			this->hard->Name = L"hard";
			this->hard->Size = System::Drawing::Size(213, 22);
			this->hard->Text = L"Сложный (24x24, 99 мин)";
			this->hard->Click += gcnew System::EventHandler(this, &MyForm::hard_Click);
			// 
			// help
			// 
			this->help->Name = L"help";
			this->help->Size = System::Drawing::Size(221, 22);
			this->help->Text = L"Руководство";
			this->help->Click += gcnew System::EventHandler(this, &MyForm::help_Click);
			// 
			// exit
			// 
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(221, 22);
			this->exit->Text = L"Выход";
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::exit_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 260);
			this->Controls->Add(this->exitbtn);
			this->Controls->Add(this->helpbtn);
			this->Controls->Add(this->timelabel);
			this->Controls->Add(this->flagslabel);
			this->Controls->Add(this->hardbtn);
			this->Controls->Add(this->mediumbtn);
			this->Controls->Add(this->easybtn);
			this->Controls->Add(this->title);
			this->Controls->Add(this->menu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menu;
			this->MaximizeBox = false;
			this->Name = L"MyForm1";
			this->Text = L"Сапёр";
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void easybtn_Click(System::Object^ sender, System::EventArgs^ e) {
		startgame(diff::easy);
	}
	private: System::Void mediumbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		startgame(diff::medium);
	}
	private: System::Void hardbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		startgame(diff::hard);
	}
	private: System::Void helpbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(L"Сапёр: открой все клетки без мин!\nЛевый клик — открыть клетку.\nПравый клик — поставить или убрать флаг.\nСложности:\n- Лёгкий: 8x8, 10 мин\n- Средний: 16x16, 40 мин\n- Сложный: 24x24, 99 мин\nВыигрыш: открыть все клетки без мин.", L"Руководство");
	}
	private: System::Void exitbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void newgame_Click(System::Object^ sender, System::EventArgs^ e) {
		startgame(nowdiff);
	}
	private: System::Void mainmenu_Click(System::Object^ sender, System::EventArgs^ e) {
		showmenu();
	}
	private: System::Void easy_Click(System::Object^ sender, System::EventArgs^ e) {
		startgame(diff::easy);
	}
	private: System::Void medium_Click(System::Object^ sender, System::EventArgs^ e) {
		startgame(diff::medium);
	}
	private: System::Void hard_Click(System::Object^ sender, System::EventArgs^ e) {
		startgame(diff::hard);
	}
	private: System::Void help_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(L"Сапёр: открой все клетки без мин!\nЛевый клик — открыть клетку.\nПравый клик — поставить или убрать флаг.\nСложности:\n- Лёгкий: 8x8, 10 мин\n- Средний: 16x16, 40 мин\n- Сложный: 24x24, 99 мин\nВыигрыш: открыть все клетки без мин.", L"Руководство");
	}
	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		sec++;
		timelabel->Text = L"Time: " + sec;
	}
		   void startgame(diff difficulty) {
			   nowdiff = difficulty;
			   title->Visible = false;
			   easybtn->Visible = false;
			   mediumbtn->Visible = false;
			   hardbtn->Visible = false;
			   helpbtn->Visible = false;
			   exitbtn->Visible = false;

			   menu->Visible = true;
			   flagslabel->Visible = true;
			   timelabel->Visible = true;
			   sec = 0;
			   timelabel->Text = L"Time: 0";
			   timer->Start();
			   if (buttons != nullptr)
			   {
				   for (int i = 0; i < size; i++)
					   for (int j = 0; j < size; j++)
						   Controls->Remove(buttons[i, j]);
			   }

			   if (difficulty == diff::easy)
			   {
				   size = 8;
				   mines = 10;
				   ClientSize = System::Drawing::Size(260, 330);
			   }
			   else if (difficulty == diff::medium)
			   {
				   size = 16;
				   mines = 40;
				   ClientSize = System::Drawing::Size(500, 570);
			   }
			   else
			   {
				   size = 24;
				   mines = 99;
				   ClientSize = System::Drawing::Size(740, 810);
			   }
			   buttons = gcnew array<Button^, 2>(size, size);
			   mine = gcnew array<bool, 2>(size, size);
			   nums = gcnew array<int, 2>(size, size);
			   opened = gcnew array<bool, 2>(size, size);
			   flags = gcnew array<bool, 2>(size, size);
			   flagcount = mines;
			   isGameOver = false;
			   try
			   {
				   flagimg = Image::FromFile("Resources\\flag.png");
				   mineimg = Image::FromFile("Resources\\mine.png");
			   }
			   catch (Exception^)
			   {
				   flagimg = nullptr;
				   mineimg = nullptr;
			   }
			   flagslabel->Text = L"Flags: " + flagcount;
			   for (int i = 0; i < size; i++)
			   {
				   for (int j = 0; j < size; j++)
				   {
					   buttons[i, j] = gcnew Button();
					   buttons[i, j]->Size = System::Drawing::Size(30, 30);
					   buttons[i, j]->Location = Point(10 + j * 30, 60 + i * 30);
					   buttons[i, j]->Tag = gcnew Point(i, j);
					   buttons[i, j]->Click += gcnew EventHandler(this, &MyForm::button_click);
					   buttons[i, j]->MouseDown += gcnew MouseEventHandler(this, &MyForm::button_mousedown);
					   buttons[i, j]->TabStop = false;
					   Controls->Add(buttons[i, j]);
				   }
			   }
			   reset();
		   }
		   void showmenu() {
			   timer->Stop();
			   if (buttons != nullptr)
			   {
				   for (int i = 0; i < size; i++)
					   for (int j = 0; j < size; j++)
						   Controls->Remove(buttons[i, j]);
				   buttons = nullptr;
			   }
			   menu->Visible = false;
			   flagslabel->Visible = false;
			   timelabel->Visible = false;

			   ClientSize = System::Drawing::Size(260, 260);
			   title->Visible = true;
			   easybtn->Visible = true;
			   mediumbtn->Visible = true;
			   hardbtn->Visible = true;
			   helpbtn->Visible = true;
			   exitbtn->Visible = true;
		   }
		   void reset()
		   {
			   for (int i = 0; i < size; i++)
				   for (int j = 0; j < size; j++)
				   {
					   mine[i, j] = false;
					   nums[i, j] = 0;
					   opened[i, j] = false;
					   flags[i, j] = false;
					   buttons[i, j]->Text = L"";
					   buttons[i, j]->Image = nullptr;
					   buttons[i, j]->Enabled = true;
				   }

			   flagcount = mines;
			   flagslabel->Text = L"Flags: " + flagcount;
			   isGameOver = false;

			   Random^ r = gcnew Random();
			   int k = 0;
			   while (k < mines)
			   {
				   int x = r->Next(size);
				   int y = r->Next(size);
				   if (!mine[x, y])
				   {
					   mine[x, y] = true;
					   k++;
				   }
			   }

			   for (int i = 0; i < size; i++)
				   for (int j = 0; j < size; j++)
					   if (!mine[i, j])
						   nums[i, j] = countmines(i, j);
		   }
		   int countmines(int x, int y)
		   {
			   int c = 0;
			   for (int i = x - 1; i <= x + 1; i++)
				   for (int j = y - 1; j <= y + 1; j++)
					   if (i >= 0 && i < size && j >= 0 && j < size && mine[i, j])
						   c++;
			   return c;
		   }
		   void open(int x, int y)
		   {
			   if (x < 0 || x >= size || y < 0 || y >= size || opened[x, y] || flags[x, y])
				   return;

			   opened[x, y] = true;
			   buttons[x, y]->Enabled = false;
			   this->Focus();
			   buttons[x, y]->BackColor = Color::LightGray;

			   if (mine[x, y])
			   {
				   buttons[x, y]->Image = mineimg;
				   buttons[x, y]->BackColor = Color::Red;
				   gameover(false);
				   return;
			   }

			   if (nums[x, y] > 0)
				   buttons[x, y]->Text = nums[x, y].ToString();
			   else
				   for (int i = x - 1; i <= x + 1; i++)
					   for (int j = y - 1; j <= y + 1; j++)
						   open(i, j);

			   checkwin();
		   }

		   void gameover(bool win)
		   {
			   isGameOver = true;
			   timer->Stop();
			   for (int i = 0; i < size; i++)
				   for (int j = 0; j < size; j++)
				   {
					   buttons[i, j]->Enabled = false;
					   if (mine[i, j])
						   buttons[i, j]->Image = mineimg;
				   }
			   MessageBox::Show(win ? L"Ты выиграл!" : L"Ты проиграл!", L"Конец");
		   }

		   void checkwin()
		   {
			   int openedcount = 0;
			   for (int i = 0; i < size; i++)
				   for (int j = 0; j < size; j++)
					   if (opened[i, j])
						   openedcount++;
			   if (openedcount == size * size - mines)
				   gameover(true);
		   }

		   void button_click(Object^ sender, EventArgs^ e)
		   {
			   if (isGameOver) return;
			   Button^ b = safe_cast<Button^>(sender);
			   Point^ p = safe_cast<Point^>(b->Tag);
			   open(p->X, p->Y);
		   }

		   void button_mousedown(Object^ sender, MouseEventArgs^ e)
		   {
			   if (isGameOver || e->Button != System::Windows::Forms::MouseButtons::Right) return;
			   Button^ b = safe_cast<Button^>(sender);
			   Point^ p = safe_cast<Point^>(b->Tag);
			   int x = p->X;
			   int y = p->Y;

			   if (!opened[x, y])
			   {
				   if (!flags[x, y] && flagcount > 0)
				   {
					   flags[x, y] = true;
					   b->Image = flagimg;
					   flagcount--;
				   }
				   else if (flags[x, y])
				   {
					   flags[x, y] = false;
					   b->Image = nullptr;
					   flagcount++;
				   }
				   flagslabel->Text = L"Flags: " + flagcount;
				   this->Focus();
			   }
		   }
	};
}