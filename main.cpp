#include <iostream>
#include <string>

class Mamifero {
  public:
    Mamifero(std::string dieta, std::string nacimiento) : dieta(dieta), nacimiento(nacimiento) {}

    std::string getDieta() const { return dieta; }
    std::string getNacimiento() const { return nacimiento; }

    bool operator==(const Mamifero& otro) const { return dieta == otro.dieta && nacimiento == otro.nacimiento; }
    bool operator!=(const Mamifero& otro) const { return !(*this == otro); }
    bool operator<(const Mamifero& otro) const { return dieta < otro.dieta && nacimiento < otro.nacimiento; }
    bool operator>(const Mamifero& otro) const { return otro < *this; }
    Mamifero operator+(const Mamifero& otro) const { return Mamifero(dieta + otro.dieta, nacimiento + otro.nacimiento); }

  private:
    std::string dieta;
    std::string nacimiento;
};

class Felino : public Mamifero {
  public:
    Felino(std::string dieta, std::string nacimiento, std::string raza, std::string circo) : Mamifero(dieta, nacimiento), raza(raza), circo(circo) {}

    std::string getRaza() const { return raza; }
    std::string getCirco() const { return circo; }

    void setCirco(const std::string& nuevoCirco) { circo = nuevoCirco; }

  private:
    std::string raza;
    std::string circo;
};

class GatoDomestico : public Felino {
  public:
    GatoDomestico(std::string dieta, std::string nacimiento, std::string raza, std::string dueno) : Felino(dieta, nacimiento, raza, ""), dueno(dueno) {}

    std::string getDueno() const { return dueno; }

    void setDueno(const std::string& nuevoDueno) { dueno = nuevoDueno; }

  private:
    std::string dueno;
};

int main() {
    int opc;
    std::string nuevoDueno, nuevoCirco;
    GatoDomestico Minino("Comida para gatos", "2020, Espana", "Siames", "Juan");
    Felino EstrellaCirco("Comida para felinos", "2019, Mexico", "Leopardo", "Nacional");
    do
    {
        std::cout<<
        "\n1.-Imprimir la dieta de Minino y de EstrellaCirco"
        "\n2.-Imprimir el anio y lugar de nacimiento de Minino y de EstrellaCirco"
        "\n3.-Cambiar el nombre del duenio de Minino"
        "\n4.-Imprimir la raza de Minino y de EstrellaCirco"
        "\n5.-Cambiar el nombre del circo en el que actua EstrellaCirco"
        "\n6.-Salir"<<std::endl;
        std::cin>>opc;
        switch(opc)
        {
            case 1:
                system("cls");
                std::cout<<"Dieta Minino: \t"<<Minino.getDieta() + "\tDieta EstrellaCirco:\t"<<EstrellaCirco.getDieta()<<std::endl;
            break;

            case 2:
                system("cls");
                std::cout<<"Anio y Lugar de Nacimiento de Minino:\t"<<Minino.getNacimiento() + "\tAnio y Lugar de Nacimiento de EstrellaCirco:\t"<<EstrellaCirco.getNacimiento()<<std::endl;
            break;

            case 3:
                system("cls");
                std::cout<<"Duenio Anterior:"<<Minino.getDueno()<<std::endl;
                std::cout<<"Ingrese el nuevo nombre del Duenio de minino"<<std::endl;
                std::cin>>nuevoDueno;
                Minino.setDueno(nuevoDueno);
                std::cout<<"Nuevo Duenio:"<<Minino.getDueno()<<std::endl;
            break;

            case 4:
                system("cls");
                std::cout<<"Raza Minino: \t"<<Minino.getRaza() + "\tRaza EstrellaCirco:\t"<<EstrellaCirco.getRaza()<<std::endl;
            break;

            case 5:
                system("cls");
                std::cout<<"Circo Anterior:"<<EstrellaCirco.getCirco()<<std::endl;
                std::cout<<"Ingrese el nuevo Circo"<<std::endl;
                std::cin>>nuevoCirco;
                EstrellaCirco.setCirco(nuevoCirco);
                std::cout<<"Nuevo Circo:"<<EstrellaCirco.getCirco()<<std::endl;
            break;

            case 6:
                exit(0);
            break;

            default:
                std::cout<<"\nopcion incorrecta o inexistente"<<std::endl;
            break;
        }
    }
    while(true);
    return 0;
}
