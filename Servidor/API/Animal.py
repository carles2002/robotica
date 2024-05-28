import os
import csv

class Animal:
  def __init__(self,especie, descripcion, caracteristicas, habitat, comida, estado):
    self._especie = especie
    self._descripcion = descripcion
    self._caracteristicas = caracteristicas
    self._habitat = habitat
    self._comida = comida
    self._estado = estado
    return
  
  def __init__(self):
    self._especie = None
    self._descripcion = None
    self._caracteristicas = None
    self._habitat = None
    self._comida = None
    self._estado = None
    return
#---------------------------------------------------
# GETTER
#---------------------------------------------------
  def get_especie(self):
    return self._especie
  def get_descripcion(self):
    return self._descripcion
  def get_caracteristicas(self):
    return self._caracteristicas
  def get_habitat(self):
    return self._habitat
  def get_comida(self):
    return self._comida
  def get_estado(self):
    return self._estado
    #---------------------------------------------------
    # SETTER
    #---------------------------------------------------
  def set_especie(self,especie):
    self._especie=especie
  def set_descripcion(self,descripcion):
    self._descripcion=descripcion
  def set_caracteristicas(self,caracteristicas):
    self._caracteristicas=caracteristicas
  def set_habitat(self,habitat):
    self._habitat=habitat
  def set_comida(self,comida):
    self._comida=comida
  def set_estado(self,estado):
      self._estado=estado
    #---------------------------------------------------
    # METODOS
    #---------------------------------------------------

      #---------------------------------------------------
      # especie:Txt --> get_info() --> animal:Animal
      # Descripción: Lee un csv y de sus datos devuelve la información correspondiente al animal
      # que se ha especificado con anterioridad
      #---------------------------------------------------
  def get_info(self, especie):
    datos = self.get_csv("../bbdd/animales.csv")
    
    dicres={}
    dicindex=[]
    index=None
    for item in datos:
      for i in item:
        if(item[i]==especie):
          index = i[-1]
          
    for item in datos:
      for i in item:
        if(i[-1]==index):
          dicindex.append(i)
          
    for item in datos:
      for index in dicindex:
        dicres[index]=item[index]
    
    self.set_parametros(dicres,index)
    return
      
  def get_csv(self,filename):
    dicres={}
    with open(filename, newline='', encoding="utf-8-sig") as csvfile:
      spamreader = csv.DictReader(csvfile, delimiter=';', quotechar='|')
      
      lista=[]
      index=1
      for row in spamreader:
        for i in row:
          #dicres[i+str(index)]=row.get(i)
          dicres[i+str(index)]=row.get(i)
        index+=1
      lista.append(dicres)
      
    return lista
  
  def set_parametros(self,datos,index):
    for item in datos:
      campo="_"+(item[:-1]).lower()
      if(campo=="_especie"):
        self.set_especie(datos[item])
      if(campo=="_descripcion"):
        self.set_descripcion(datos[item])
      if(campo=="_caracteristicas"):
        self.set_caracteristicas(datos[item])
      if(campo=="_habitat"):
        self.set_habitat(datos[item])
      if(campo=="_comida"):
        self.set_comida(datos[item])
      if(campo=="_estado"):
        self.set_estado(datos[item])
      else:
        self.set_estado("Desconocido")

    return