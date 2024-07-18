#pragma once

#include <map>
#include <string>

#include "selfdrive/ui/sunnypilot/sp_priv_ui.h"
#include "selfdrive/ui/sunnypilot/qt/widgets/sp_priv_controls.h"
#include "selfdrive/ui/sunnypilot/qt/widgets/sp_priv_scrollview.h"

class AutoLaneChangeTimer : public OptionControlSP {
  Q_OBJECT

public:
  AutoLaneChangeTimer();

  void refresh();

signals:
  void toggleUpdated();

private:
  Params params;
};

class PauseLateralSpeed : public OptionControlSP {
  Q_OBJECT

public:
  PauseLateralSpeed();

  void refresh();

  signals:
    void ToggleUpdated();

private:
  Params params;
};


class LaneChangeSettings : public QWidget {
  Q_OBJECT

public:
  explicit LaneChangeSettings(QWidget* parent = nullptr);
  void showEvent(QShowEvent *event) override;

signals:
  void backPress();

public slots:
  void updateToggles();

private:
  Params params;
  std::map<std::string, ParamControlSP*> toggles;

  AutoLaneChangeTimer *auto_lane_change_timer;
  PauseLateralSpeed *pause_lateral_speed;
};
