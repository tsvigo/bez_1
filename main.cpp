#include <QCoreApplication>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief main
/// \param argc
/// \param argv
/// \return 
///
#include <fstream>
#include <iostream>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int variable_synapse_index_counter=0;
long long variable_error;
int var ;
using namespace std;
/// 
/// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор ///////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is(
        // "/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/neurons_and_signal.txt" // 1.bmp
        //   "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1/neyroni_i_signal.txt" // 1-1.bmp
        
        "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/0/neyroni_i_signal.txt"
        
        //NOTE: считывание в вектор нейронов и сигналов из файла (НАДО Менять для подстройки)
        );
    std::istream_iterator<unsigned long long> start(is), end;
    std::vector<unsigned long long> list_of_neurons(start, end);
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// загрузка синапсов из файла в вектор //////////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is2("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt-4");
    std::istream_iterator<unsigned long long> start2(is2), end2;
    std::vector<unsigned long long> list_of_synapses(start2, end2);
    // f:
    // std::jmp_buf f;
    // std::longjmp(f, true); // Go to error handler
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // *** начало блока ***
    
    // TODO: После настройки надо включить (раскомментировать) загрузку из файла error
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//    if (
////        fileExists(
////          //  "/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors_GUI/error.txt"
////            "/home/viktor/my_projects_qt_2/bez_1/error.txt"
////            )==true 
//         QFileInfo::exists(
//            "/home/viktor/my_projects_qt_2/bez_1/error.txt"
//            ) && QFileInfo(
//                   "/home/viktor/my_projects_qt_2/bez_1/error.txt"
//                   ).isFile()
//        )
//        // 
//    {;;
//        // считываем ошибку из файла
//        QFile file(
//          //  "/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors_GUI/error.txt"
//              "/home/viktor/my_projects_qt_2/bez_1/error.txt"
//            );
//        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//        {;;}
//        QByteArray line = file.readLine();
//        file.close();
//        bool ok;
//        variable_error=line.toLongLong (&ok,10);//.toLongLong ();
//    }
//    else
        // если файла с ошибкой нет
        
        // *** конец блока ***
        
        // если хотим включить настройку сопротивлений синапсов блок отсюда и выше до 66 строки закомментируем (отключим)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    variable_error     =   1073741824-list_of_neurons[200] ;
/// 
 if  ( variable_error <=0)
    {
       
  std::cout << "Программа считает что это 1." << std::endl;
 }
    else {        std::cout << "Программа считает что это не 1." << std::endl;    } //  меняем на это не 1
/// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // если ошибки нет то на выход
 if (variable_error<=0) // тут видимо надо менять на если ошибка = или > то на выход то есть ошибка пропадает если становится > 0
     goto d;
 std::cout << "variable_error = " << variable_error<< std::endl;
 std::cout << "Variable error = 1073741824-list_of_neurons[200] = " << 1073741824-list_of_neurons[200]<< std::endl;
 std::cout << "list_of_neurons[200]  = " << list_of_neurons[200]  << std::endl;

b:
///
    // NOTE: решение
//////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
    for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
        
        {
            // sigpe арифметическое исключение: (СИНАПСЫ бЫЛИ 0 ДЕление на 0)
            list_of_neurons[var]=list_of_neurons[var]+  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]);    
        }
    }
    
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
        list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]);
    }
    variable_error     =   1073741824-list_of_neurons[200] ;
    if (variable_error<=0) // to the exit
        // goto c;
        goto d;
    if (list_of_synapses[10100]==1) // to the exit
    {
        std::cout << "The values of all synapses are minimal and equal to 1." << std::endl;
        goto d;
    }
e:             // TODO: тут видимо менять условия - края и не -1 а +1
    if (list_of_synapses[variable_synapse_index_counter] <2147483646) // < 2147483646
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]+1;  // +1
    
    if (list_of_synapses[variable_synapse_index_counter] ==2147483646) //  == 2147483646
    {
        variable_synapse_index_counter = variable_synapse_index_counter+1;
        goto e;
    }
    if (variable_synapse_index_counter<10100)
        variable_synapse_index_counter=variable_synapse_index_counter+1;
    else
        variable_synapse_index_counter=0;
    goto b;
d:
    fstream file;
    file.open("/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors/synapses.txt-4",ios_base::out);
    
    vector<unsigned long long>::iterator itr;
    
    for(itr=list_of_synapses.begin();itr!=list_of_synapses.end();itr++)
    {
        file<<*itr<<endl;
    }
    
    file.close();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "The error has disappeared. Variable error = " << variable_error<< ". Это выход. "<<std::endl;
            std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    // При нажатии на кнопку "Не правильно" надо ошибку изменить на 0   
// Записать ошибку в файл
    QFile fileOut(
               // "/home/viktor/my_projects_qt_2/cycle_of_distinguishing_a_one_with_vectors_GUI/error.txt"
                 "/home/viktor/my_projects_qt_2/bez_1/error.txt"
                ); // Связываем объект с файлом fileout.txt
    if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)) 
    { // Если файл успешно открыт для записи в текстовом режиме
        QTextStream writeStream(&fileOut); // Создаем объект класса QTextStream
        // и передаем ему адрес объекта fileOut
        writeStream << //long long
            QString::number(variable_error); // Посылаем строку в поток для записи
        fileOut.close(); // Закрываем файл
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if  ( variable_error <=0)
    {
        
        std::cout << "Программа считает что это 1." << std::endl;
    }
    else {        std::cout << "Программа считает что это не 1." << std::endl;    } //  меняем на это не 1
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///      
    return a.exec();
}
