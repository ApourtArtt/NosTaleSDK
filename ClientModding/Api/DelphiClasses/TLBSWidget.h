#pragma once
#include "TObject.h"
#include "TLBSWidgetList.h"
#include "../Properties/Graphical/Border.h"
#include "../Properties/Graphical/Cursor.h"
#pragma pack(push, 1)

class TLBSWidget : public TObject
{
public:
    explicit TLBSWidget() {} // Allows deep copy
    TLBSWidget(uint32_t VTable, int8_t EvenThing, TLBSWidget* Parent, TLBSWidgetList* Children, Border Border)
        : evenThing(EvenThing)
        , parent(Parent)
        , children(Children)
        , border(Border)
    {
        vTable = VTable;
        visible = false;
        if (children == nullptr)
            children = new TLBSWidgetList();
        unknownWidget = nullptr;
        isHandlingClick = false;
        isLastWidgetClicked = false;
        savePosition = false; // Maybe true ?
        cursor = Cursor::Normal;
    }

    TLBSWidget* getParent() const { return parent; }

    void setWidgetPosition(int16_t X, int16_t Y)
    {
        border.botRightX = (border.botRightX - border.topLeftX) + abs(X);
        border.botRightY = (border.botRightY - border.topLeftY) + abs(Y);
        border.topLeftX = X;
        border.topLeftY = Y;
    }

    void setWidgetSize(int16_t SizeX, int16_t SizeY)
    {
        border.botRightX = border.topLeftX + SizeX;
        border.botRightY = border.topLeftY + SizeY;
    }

    void incrementSize(int16_t incX, int16_t incY)
    {
        border.botRightX += incX;
        border.botRightY += incY;
    }

    void moveWidget(int16_t incX, int16_t incY)
    {
        border.botRightX += incX;
        border.botRightY += incY;
        border.topLeftX += incX;
        border.topLeftY += incY;
    }

    void addWidget(TLBSWidget* Child)
    {
        children->push_back(Child);
        Child->setWidgetParent(this);
    }

    void setCursor(Cursor Cursor, bool UseCustomCursor)
    {
        cursor = Cursor;
        useCustomCursor = UseCustomCursor;
    }

    std::vector<TLBSWidget*> findClasses(const std::string& ClassName)
    {
        if (children == nullptr)
        {
            Logger::Error("children == nullptr");
            return {};
        }

        auto classInfo = ClassSearcher::GetClassInfoFromName(ClassName);
        if (classInfo.GetName() != ClassName)
        {
            Logger::PushPopModuleName("TLBSWidget");
            Logger::Error("Class %s not found", ClassName.c_str());
            return {};
        }

        std::vector<TLBSWidget*> widgets;

        for (auto i = 0; i < children->size(); i++)
        {
            if (classInfo.GetVTable() == children->getItem(i)->getVTable())
                widgets.push_back(children->getItem(i));
        }

        return widgets;
    }

    std::vector<TLBSWidget*> findClasses(std::string_view ClassName)
    {
        return findClasses(std::string(ClassName.data()));
    }

    std::vector<TLBSWidget*> findClassesWithExpectedSize(const std::string& ClassName, uint32_t Size)
    {
        if (children == nullptr)
        {
            Logger::Error("children == nullptr");
            return {};
        }

        auto classInfo = ClassSearcher::GetClassInfoFromName(ClassName);
        if (classInfo.GetName() != ClassName)
        {
            Logger::PushPopModuleName("TLBSWidget");
            Logger::Error("Class %s not found", ClassName.c_str());
            return {};
        }

        std::vector<TLBSWidget*> widgets;

        for (auto i = 0; i < children->size(); i++)
        {
            if (children == nullptr)
            {
                Logger::Error("Child n%d == nullptr", i);
                continue;
            }
            if (classInfo.GetVTable() == children->getItem(i)->getVTable())
                widgets.push_back(children->getItem(i));
        }

        if (widgets.size() != Size)
        {
            Logger::Error("Expected size of %d, have %d, for %s", Size, widgets.size(), ClassName.c_str());
            for (auto i = 0; i < widgets.size(); i++)
                Logger::Error("Child n%d == %x", i, widgets[i]);
            return {};
        }

        return widgets;
    }

    std::vector<TLBSWidget*> findClassesWithExpectedSize(std::string_view ClassName, uint32_t Size)
    {
        return findClassesWithExpectedSize(std::string(ClassName.data()), Size);
    }

    void setWidgetBorder(Border Border) { border = Border; }
    void setWidgetParent(TLBSWidget* Parent) { parent = Parent; } // TODO : remove from the parent if it is already in it
    void setVisible(bool IsVisible) { visible = IsVisible; }
    void setHandlingClick(bool IsHandlingClick) { isHandlingClick = IsHandlingClick; }
    void shouldSavePosition(bool SavePosition) { savePosition = SavePosition; }
    TLBSWidgetList getChildren() { return *children; }
    bool isVisible() const { return visible; }
    int getWidth() const { return border.botRightX - border.topLeftX; }
    int getHeight() const { return border.botRightY - border.topLeftY; }
    Border getBorder() const { return border; }

protected:
    int8_t evenThing;           // 0x04 Unknown use yet
    char unknown1[3];           // 0x05 Unknown
    TLBSWidget* parent;         // 0x08 Widget holding this one
    TLBSWidget* unknownWidget;  // 0x0C Unknown 
    Border border;              // 0x10
    bool visible;               // 0x18 Is the widget visible ?
    bool isHandlingClick;       // 0x19 Is the widget supposed to react on click ? Care : the whole Border describe the widget area
    bool isLastWidgetClicked;   // 0x1A Is the widget the last widget clicked ?
    bool savePosition;          // 0x1B If true, widget can change from to front or behind other widget (little bit complicated with minimapwidget)
    char unknown2[2];           // 0x1C Unknown
    Cursor cursor;              // 0x1E
    bool useCustomCursor;       // 0x1F
    TLBSWidgetList* children;     // 0x20 List of childs
};
static_assert(sizeof(TLBSWidget) == 0x24, "TLBSWidget does not have a size of 0x24.");

#pragma pack(pop)
