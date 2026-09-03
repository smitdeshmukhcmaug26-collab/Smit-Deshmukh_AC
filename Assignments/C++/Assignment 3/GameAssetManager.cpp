#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Texture{

    private:
    string name;
    int width;
    int height;

    public:

    Texture(const string& name, int width, int height) : name(name), width(width), height(height){
        cout << "[Texture Loaded]" << name << " "<< height << " " << width << endl;
    }

    ~Texture(){
        cout << "[Texture Released]" << name << endl;
        cout << "";
    }

    void display() const{
        cout << "Displaying Texture: "<< name << " " << width << " " << height << endl;
        
    }

};

class Shader{

    private:
    string name;
    string type;

    public:

    Shader(const string& name, const string& type ) : name(name), type(type){
        cout << "[Shader Compiled]" << name << " "<< name << " " << type << endl;
    }

    ~Shader(){
        cout << "[Texture Destroyed]" << name << " " << type << endl;
    }

};

int getReferenceCount(const shared_ptr<Shader>& ptr){
        return ptr.use_count();
    }

class AudioClip{

    private:
    string name;
    double volume;

    public:

    AudioClip(const string& name, double volume) : name(name), volume(volume){
        cout <<"Clip Loaded" << endl;
    }

    ~AudioClip(){
        cout <<"Clip Released"<< endl;
    }

    string getName() const {
        return name;
    }

};

int main(){

    auto tex1 = make_unique<Texture>("Player_Sprite", 512, 512);
    tex1->display();

    // unique_ptr‹Texture> tex2 = tex1 : unique ptr copy constructor is deleted due to which shared ownership is not possible.

    unique_ptr<Texture> tex2 = move(tex1);
    cout << "tex1 is null:" << (tex1 == nullptr ? "Yes" : "No") << endl;

    if(tex2){
        tex2->display();
    }

    auto shader = make_shared<Shader>("main_vert", "vertex");
    cout << "Ref count: "<< shader.use_count() << endl;

    {
        auto rendererRef = shader;
        cout << "Ref count: " << shader. use_count() << endl;

        auto editorRef = shader;
        cout << "Ref count: " << shader. use_count() << endl;
    }

    cout << "Ref count: " << shader. use_count() << endl;

    auto audio = make_shared<AudioClip>("explosion", 3.5);
    weak_ptr<AudioClip> observer = audio;

    if(auto clip = observer.lock()){
        cout << "Clip alive: " << clip->getName() << endl;

        audio.reset();
    }

    if(observer.expired()){
        cout << "Clip already unloaded " << endl;
    }

    return 0;
}
