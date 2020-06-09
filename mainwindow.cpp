#include "mainwindow.h"
#include "ui_mainwindow.h"

#define COLUMNS 4

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    books.push_back(Book(ui->comboBox->currentText(),
                         ui->lineEdit_2->text(),
                         ui->spinBox->value(),
                         ui->lineEdit->text()));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(books.size());
    ui->tableWidget->setColumnCount(COLUMNS);
    ui->tableWidget->setHorizontalHeaderLabels({"Назва", "Автор", "Рік", "Жанр"});
    for (auto i = 0; i < books.size(); i++) {
              ui->tableWidget->setItem(i, 0, new QTableWidgetItem(books[i].getName()));
              ui->tableWidget->setItem(i, 1, new QTableWidgetItem(books[i].getAuthor()));
              ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(books[i].getYear())));
              ui->tableWidget->setItem(i, 3, new QTableWidgetItem(books[i].getGenre()));
    }
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::Stretch);
}



void MainWindow::on_pushButton_3_clicked()
{
    QString name[] = {"Повість минулих літ", "Місто", "Кобзар", "Корона", "Чорна рада"};
    QString author[] = {"Шевченко", "Франко", "Орвелл", "Коцюбинський", "Ван"};
    QString genre[] = {"Комедія", "Трагедія", "Новела", "Повість", "Роман", "Драма"};
    int count = ui->spinBox_2->value();
    for (int i = 0; i < count; ++i) {
        books.push_back(Book(genre[rand() % 6],
                            author[rand() % 5],
                            1900 + rand() % (2020 - 1900),
                            name[rand() % 5]));
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString type = ui->comboBox_2->currentText();
    QString key = ui->lineEdit_3->text();
    std::vector<Book> tmp;
    BPTree tree;
    if (type == "Назва") {
        for (auto it = books.begin(); it < books.end(); ++it) {
            tree.search(*it);
            if (it->getName() == key) {
                tmp.push_back(*it);
            }
        }
    } else if (type == "Автор") {
        for (auto it = books.begin(); it < books.end(); ++it) {
            tree.search(*it);
            if (it->getAuthor() == key) {
                tmp.push_back(*it);
            }
        }
    } else if (type == "Рік") {
        for (auto it = books.begin(); it < books.end(); ++it) {
            tree.search(*it);
            if (it->getYear() == key) {
                tmp.push_back(*it);
            }
        }
    } else if (type == "Жанр") {
        for (auto it = books.begin(); it < books.end(); ++it) {
            tree.search(*it);
            if (it->getGenre() == key) {
                tmp.push_back(*it);
            }
        }
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(tmp.size());
    ui->tableWidget->setColumnCount(COLUMNS);
    ui->tableWidget->setHorizontalHeaderLabels({"Назва", "Автор", "Рік", "Жанр"});
    for (auto i = 0; i < tmp.size(); i++) {
              ui->tableWidget->setItem(i, 0, new QTableWidgetItem(tmp[i].getName()));
              ui->tableWidget->setItem(i, 1, new QTableWidgetItem(tmp[i].getAuthor()));
              ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(tmp[i].getYear())));
              ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tmp[i].getGenre()));
    }
}

std::vector<Book> insertionSort(std::vector<Book> data)
{
    int i, j;
    Book key;
    for (i = 1; i < data.size(); i++)
    {
        key = data[i];
        j = i - 1;

        while (j >= 0 && data[j].getYear() > key.getYear())
        {
            data[j + 1] =data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
    return data;
}

std::vector<Book> mergeSort(std::vector<Book> data)
{
    int index = 0;

    while (index < data.size()) {
        if (index == 0)
            index++;
        if (data[index].getYear() >= data[index - 1].getYear())
            index++;
        else {
            std::swap(data[index], data[index - 1]);
            index--;
        }
    }
    return data;
}

std::vector<Book> selectionSort(std::vector<Book> data)
{
    int i, j, min_idx;
    for (i = 0; i < data.size() - 1; i++)
    {
        min_idx = i;
        for (j = i+1; j < data.size(); j++)
        if (data[j].getYear() < data[min_idx].getYear())
            min_idx = j;

        // Swap the found minimum element with the first element
        std::swap(data[min_idx], data[i]);
    }
    return data;
}

std::vector<Book> quickSort(std::vector<Book> data)
{
    for (int gap = data.size()/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < data.size(); i += 1)
        {
            Book temp = data[i];

            int j;
            for (j = i; j >= gap && data[j - gap].getYear() > temp.getYear(); j -= gap)
                data[j] = data[j - gap];
            data[j] = temp;
        }
    }
    return data;
}

void MainWindow::on_pushButton_5_clicked()
{
    QString algo = ui->comboBox_3->currentText();
    std::vector<Book> data;
    if (algo == "Insertion sort") {
        data = insertionSort(books);
    } else if (algo == "Quicksort") {
        data = quickSort(books);
    } else if (algo == "Merge sort") {
        data = mergeSort(books);
    } else if (algo == "Counting sort") {
        data = selectionSort(books);
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(COLUMNS);
    ui->tableWidget->setHorizontalHeaderLabels({"Назва", "Автор", "Рік", "Жанр"});
    for (auto i = 0; i < data.size(); i++) {
              ui->tableWidget->setItem(i, 0, new QTableWidgetItem(data[i].getName()));
              ui->tableWidget->setItem(i, 1, new QTableWidgetItem(data[i].getAuthor()));
              ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data[i].getYear())));
              ui->tableWidget->setItem(i, 3, new QTableWidgetItem(data[i].getGenre()));
    }
}
