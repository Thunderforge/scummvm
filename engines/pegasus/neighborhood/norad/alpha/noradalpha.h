/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1995-1997 Presto Studios, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PEGASUS_NEIGHBORHOOD_NORAD_ALPHA_NORADALPHA_H
#define PEGASUS_NEIGHBORHOOD_NORAD_ALPHA_NORADALPHA_H

#include "pegasus/neighborhood/norad/norad.h"

namespace Pegasus {

class Item;
class SubChase;

class NoradAlpha : public Norad {
friend class SubChase;
public:
	NoradAlpha(InputHandler *, PegasusEngine *);
	~NoradAlpha() override;

	void init() override;
	void start() override;

	bool okayToJump() override;

	void playClawMonitorIntro() override;

	void getExtraCompassMove(const ExtraTable::Entry &, FaderMoveSpec &) override;

	void turnOnFillingStation();
	void turnOffFillingStation();
	Item *getFillingItem() { return _fillingStationItem; }
	bool gasCanisterIntake();

	void takeItemFromRoom(Item *) override;
	void dropItemIntoRoom(Item *, Hotspot *) override;

	GameInteraction *makeInteraction(const InteractionID) override;

	void getClawInfo(HotSpotID &outSpotID, HotSpotID &prepSpotID, HotSpotID &clawControlSpotID,
			HotSpotID &pinchClawSpotID, HotSpotID &moveClawDownSpotID, HotSpotID &moveClawRightSpotID,
			HotSpotID &moveClawLeftSpotID, HotSpotID &moveClawUpSpotID, HotSpotID &clawCCWSpotID,
			HotSpotID &clawCWSpotID, uint32 &, const uint32 *&) override;

	void loadAmbientLoops() override;

	Common::Path getEnvScanMovie() override;
	uint getNumHints() override;
	Common::Path getHintMovie(uint) override;
	void setUpAIRules() override;

	void setSubPrepFailed(bool value) { _subPrepFailed = value; }
	bool getSubPrepFailed() { return _subPrepFailed; }

	void closeDoorOffScreen(const RoomID, const DirectionConstant) override;
	void findSpotEntry(const RoomID, const DirectionConstant, SpotFlags, SpotTable::Entry &) override;
	void clickInHotspot(const Input &, const Hotspot *) override;

	void checkContinuePoint(const RoomID, const DirectionConstant) override;

	void setSoundFXLevel(const uint16) override;

	bool canSolve() override;
	void doSolve() override;

protected:
	static const uint32 _noradAlphaClawExtras[22];

	virtual void arriveAtNorad01();
	virtual void arriveAtNorad01East();
	virtual void arriveAtNorad01West();
	virtual void arriveAtNorad04();
	virtual void arriveAtNorad22();

	void arriveAt(const RoomID, const DirectionConstant) override;
	void turnTo(const DirectionConstant) override;

	void startExtraSequence(const ExtraID, const NotificationFlags, const InputBits) override;

	void getZoomEntry(const HotSpotID, ZoomTable::Entry &) override;
	TimeValue getViewTime(const RoomID, const DirectionConstant) override;

	void receiveNotification(Notification *, const NotificationFlags) override;

	void activateHotspots() override;

	Hotspot *getItemScreenSpot(Item *, DisplayElement *) override;

	void bumpIntoWall() override;

	Hotspot _thermalScanSpot;

	Movie _extraMovie;
	NotificationCallBack _extraMovieCallBack;

	Item *_fillingStationItem;

	bool _subPrepFailed;

	Common::Path getSoundSpotsName() override;
	Common::Path getNavMovieName() override;
};

} // End of namespace Pegasus

#endif
