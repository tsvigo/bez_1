#include <QCoreApplication>
//###########################################################################
#include <QDataStream>
#include <QDebug>
#include <QFile>


#include <QFileDialog>

#include <QProcess>

#include <fstream>
#include <iostream>
#include <QApplication>
//#include <QWidget>
//############################ переменные: ###############################################
int var;
int neuron_index = 0, synapse_index = 0;
std::vector<long long> list_of_neurons;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//######################## нейроны ##################################################
// Функция для чтения 205 long long чисел из бинарного файла
std::vector<long long> read205LongLongFromBinaryFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Ошибка открытия бинарного файла.");
    }

    std::vector<long long> list_of_neurons(205);
    file.read(reinterpret_cast<char *>(list_of_neurons.data()), 205 * sizeof(long long));

    if (file.gcount() != 205 * sizeof(long long)) {
        throw std::runtime_error("Недостаточно данных в бинарном файле.");
    }

    return list_of_neurons;
}
//###########################################################################
// Функция для чтения чисел из бинарного файла (синапсы)
std::vector<unsigned long long> readNumbersFromFile2(const QString &fileName, size_t count)
{
    std::vector<unsigned long long> list_of_synapses;
    list_of_synapses.reserve(count);

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Failed to open file for reading." << std::endl;
        return list_of_synapses;
    }

    QDataStream in(&file);
    unsigned long long number;
    while (list_of_synapses.size() < count && !in.atEnd()) {
        in >> number;
        list_of_synapses.push_back(number);
    }

    file.close();
    return list_of_synapses;
}
//###########################################################################
// конец объявлений функций
int main(int argc, char *argv[])
{
   // QCoreApplication a(argc, argv);
    // Используем QApplication вместо QCoreApplication, чтобы поддерживать графические компоненты
    QApplication app(argc, argv);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //########################################################################################################
    std::cout << "bez_1" << std::endl;
    //########################################################################################################
//////////////////////////////// синапсы: ///////////////////////////////////////////////////////////////////////////////////////////*
    const QString fileName
        =
        "/home/viktor/my_projects_qt_2/sgenerirovaty_sinapsi/random_sinapsi.bin"
        ; // Имя бинарного файла*/

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const size_t numberCount = 10105;
    // Чтение чисел из бинарного файла
    std::vector<unsigned long long> list_of_synapses = readNumbersFromFile2(fileName, numberCount);

    // Проверка, что прочитано правильное количество чисел
    if (list_of_synapses.size() != numberCount) {
        std::cerr << "File does not contain the expected number of numbers." << std::endl;
    }
    std::cout << "list_of_synapses.size() =" << list_of_synapses.size() << std::endl;
    std::cout << "конец чтения синапсов в вектор" << std::endl;
    std::cout << "//"
                 "#################################################################################"
                 "#######################"
              << std::endl;
//###########################################################################
    // читаем нейроны в вектор

    // Вызов диалога выбора файла
    QString fileName_neyroni = QFileDialog::getOpenFileName(nullptr, "Выберите файл",
                                                            //"/home/viktor/1_rukoy/"
                                                            "/home/viktor/1_rukoy/scale/combined_numbers/"
                                                            ,  "bin Files (*.bin)");

    // Проверка, был ли файл выбран
    if (!fileName_neyroni.isEmpty()) {
        qDebug() << "Выбранный файл:" << fileName_neyroni;
    } else {
        qDebug() << "Файл не был выбран.";
    }
    // Преобразование QString в std::string
    std::string stdFileName_neyroni = fileName_neyroni.toStdString();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    try {
        // Чтение 205 long long чисел из бинарного файла в
        //  std::vector<long long>
        list_of_neurons = read205LongLongFromBinaryFile(
            //  "/home/viktor/my_projects_qt_2/podacha_signala_long_long/combined_numbers.bin"
            stdFileName_neyroni
            );
        std::cout << "list_of_neurons.size()=" << list_of_neurons.size() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
//###########################################################################
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//###########################################################################
//###########################################################################
    // блок вычисления-решения 200 нейрона
    // проверка - решение
    for (var = 100; // первый for
         var < 200; //200;
         ++var)     // This is the range of neurons
    {
        //    if (list_of_neurons->at(200)<0) break;
        for (neuron_index = 0, synapse_index = 0;

             /*,*/ synapse_index < 10100 //, neuron_index < 200
             // при включении условия выше 200 нейрон меняется
             ;
             ++neuron_index,
             synapse_index = synapse_index + 100 // вроде тут ошибка
             )

        { // // ошибка сегментации

            try {
                list_of_neurons.at(var)
                    //###########################################################################
                    = list_of_neurons.at(var) //-5310911  // valgrind
                      + ((list_of_neurons.at(neuron_index)
                          //  /   // деление
                          -                                     // вычитаем
                          list_of_synapses.at(synapse_index))); // + на -
            } catch (const std::out_of_range &e) {
                //  std::cerr << "Caught an exception: " << e.what() << '\n';
            }

        } //
    }
    //////////////////////
    for (int neuron_index = 100, synapse_index = 10000; // второй for

         synapse_index < 10100;
         ++neuron_index, ++synapse_index) {
        //      if (list_of_synapses->at(synapse_index)!=0)
        list_of_neurons.at(200)
            //###########################################################################
            = list_of_neurons.at(200) //-5310911
              + ((list_of_neurons.at(neuron_index)
                  //  / // деление
                  -                                     // вычитание
                  list_of_synapses.at(synapse_index))); // + на -
    }

//####### конец вычисления 200 нейрона ####################################################################

 /////////////   показываем что определила программа
    if
        (list_of_neurons.at(200) < 0)
        {
        std::cout << "Программа считает что это 1." << std::endl;
    }
    if (list_of_neurons.at(200) >= 0)
    {
        std::cout << "Программа считает что это не 1." << std::endl;
    }
//########################################################################################################
    std::cout << "(после решения): list_of_neurons->at(200) = "
              << list_of_neurons.at(200) << std::endl;
/// подстройка //////////////////////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return app.exec();
}
