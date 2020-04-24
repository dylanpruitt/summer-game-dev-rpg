#ifndef STATUS_H
#define STATUS_H
#include <string>
#include <vector>

class Entity;

class Status
{
    public:
        Status ();
        virtual ~Status ();

        std::string name;

        bool is_buff = false;
        bool is_debuff = false;

        int turns_left = 1;

        virtual void on_battle_end (Entity* parent) {};

        virtual void on_parent_turn (Entity* parent) {};
    protected:

    private:
};

#endif // STATUS_H
