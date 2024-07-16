/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 RDK Management.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

/*
    This is the COM-RPC interface for managing Closed Captions styles.
*/
/* @json 1.0.0 */
struct EXTERNAL ITextTrackClosedCaptionsStyle : virtual public Core::IUnknown {
    enum {
        ID = ID_TEXT_TRACK_CLOSED_CAPTIONS_STYLE
    };

    /** Values are taken from CEA-708 standard */
    enum class FontFamily : uint8_t {
        CONTENT_DEFAULT = 0,
        MONOSPACED_SERIF = 1,
        PROPORTIONAL_SERIF = 2,
        MONOSPACE_SANS_SERIF = 3,
        PROPORTIONAL_SANS_SERIF = 4,
        CASUAL = 5,
        CURSIVE = 6,
        SMALL_CAPITAL = 7
    };

    /** Values are taken from CEA-708 standard (other than -1) */
    enum class FontSize : int8_t {
        CONTENT_DEFAULT = -1,
        SMALL = 0,
        REGULAR = 1,
        LARGE = 2,
        EXTRA_LARGE = 3
    };

    /** Values are taken from CEA-708 standard (other than -1) */
    enum class FontEdge : int8_t {
        CONTENT_DEFAULT = -1,
        NONE = 0,
        RAISED = 1,
        DEPRESSED = 2,
        UNIFORM = 3,
        LEFT_DROP_SHADOW = 4,
        RIGHT_DROP_SHADOW = 5
    };

    /** Values are taken from CEA-708 standard (other than -1) */
    struct ClosedCaptionsStyle {
        FontFamily fontFamily;
        FontSize fontSize;

        //* #rrggbb Empty string implies - use stream default
        // @restrict:7
        string fontColor;
        //* 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default
        // @restrict:-1..100
        int8_t fontOpacity;

        FontEdge fontEdge;
        //* #rrggbb Empty string implies - use stream default
        // @restrict:7
        string fontEdgeColor;

        //* #rrggbb Empty string implies - use stream default
        // @restrict:7
        string backgroundColor;
        //* 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default
        // @restrict:-1..100
        int8_t backgroundOpacity;

        //* #rrggbb Empty string implies - use stream default
        // @restrict:7
        string windowColor;
        //* 0-100% where 100% is solid and 0% is transparent. -1 implies - use stream default
        // @restrict:-1..100
        int8_t windowOpacity;
    };

    /* @event */
    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum {
            ID = ID_TEXT_TRACK_CLOSED_CAPTIONS_STYLE_NOTIFICATION
        };

        /**
         * @brief The ClosedCaptionsStyle settings has changed. Call GetClosedCaptionsStyle() to get the new settings.
         */
        virtual void OnClosedCaptionsStyleChanged() = 0; // An error in Thunder 4.4 - 4.4.2 prevents us from providing the struct

        /**
         * @brief fontFamily Changed
         */
        virtual void OnFontFamilyChanged(const FontFamily font) = 0;
        /**
         * @brief fontSize Changed
         */
        virtual void OnFontSizeChanged(const FontSize size) = 0;
        /**
         * @brief fontColor Changed
         */
        virtual void OnFontColorChanged(const string &color) = 0;
        /**
         * @brief fontOpacity Changed
         */
        virtual void OnFontOpacityChanged(const int8_t opacity) = 0;
        /**
         * @brief fontEdge Changed
         */
        virtual void OnFontEdgeChanged(const FontEdge edge) = 0;
        /**
         * @brief fontEdgeColor Changed
         */
        virtual void OnFontEdgeColorChanged(const string &color) = 0;
        /**
         * @brief backgroundColor Changed
         */
        virtual void OnBackgroundColorChanged(const string &color) = 0;
        /**
         * @brief backgroundOpacity Changed
         */
        virtual void OnBackgroundOpacityChanged(const int8_t opacity) = 0;
        /**
         * @brief windowColor Changed
         */
        virtual void OnWindowColorChanged(const string &color) = 0;
        /**
         * @brief windowOpacity Changed
         */
        virtual void OnWindowOpacityChanged(const int8_t opacity) = 0;
    };

    /** Register notification interface.
     * The callback will be called with the current settings.
     */
    virtual uint32_t Register(INotification *notification) = 0;
    /** Unregister notification interface */
    virtual uint32_t Unregister(const INotification *notification) = 0;

    // Settings

    /**
     * @brief Sets the ClosedCaptionsStyle.
     * @details For all values it is possible to keep or override the stream default.
     * The style setting will take effect immediately in all running (Closed Captions) sessions, which has not applied a custom style.
     * @param style Contains the chosen styles
     */
    virtual uint32_t SetClosedCaptionsStyle(const ClosedCaptionsStyle &style) = 0;
    /**
     * @brief Gets the current ClosedCaptionsStyle settings.
     */
    virtual uint32_t GetClosedCaptionsStyle(ClosedCaptionsStyle &style /* @out */) const = 0;

    /**
     * @{
     * @group Individual getter and setter Methods to facilitate easier Firebolt mapping
     */

    /**
     * @brief Setter for FontFamily
     */
    virtual uint32_t SetFontFamily(const FontFamily font) = 0;
    /**
     * @brief Getter for FontFamily
     */
    virtual uint32_t GetFontFamily(FontFamily &font /* @out */) const = 0;

    /**
     * @brief Setter for FontSize
     */
    virtual uint32_t SetFontSize(const FontSize size) = 0;
    /**
     * @brief Getter for FontSize
     */
    virtual uint32_t GetFontSize(FontSize &size /* @out */) const = 0;
    /**
     * @brief Setter for FontColor
     */
    virtual uint32_t SetFontColor(const string &color) = 0;

    /**
     * @brief Getter for FontColor
     */
    virtual uint32_t GetFontColor(string &color /* @out */) const = 0;
    /**
     * @brief Setter for FontOpacity
     */
    virtual uint32_t SetFontOpacity(const int8_t opacity) = 0;

    /**
     * @brief Getter for FontOpacity
     */
    virtual uint32_t GetFontOpacity(int8_t &opacity /* @out */) const = 0;
    /**
     * @brief Setter for FontEdge
     */
    virtual uint32_t SetFontEdge(const FontEdge edge) = 0;
    /**
     * @brief Getter for FontEdge
     */
    virtual uint32_t GetFontEdge(FontEdge &edge /* @out */) const = 0;

    /**
     * @brief Setter for FontEdgeColor
     */
    virtual uint32_t SetFontEdgeColor(const string &color) = 0;
    /**
     * @brief Getter for FontEdgeColor
     */
    virtual uint32_t GetFontEdgeColor(string &color /* @out */) const = 0;

    /**
     * @brief Setter for BackgroundColor
     */
    virtual uint32_t SetBackgroundColor(const string &color) = 0;
    /**
     * @brief Getter for BackgroundColor
     */
    virtual uint32_t GetBackgroundColor(string &color /* @out */) const = 0;

    /**
     * @brief Setter for BackgroundOpacity
     */
    virtual uint32_t SetBackgroundOpacity(const int8_t opacity) = 0;
    /**
     * @brief Getter for BackgroundOpacity
     */
    virtual uint32_t GetBackgroundOpacity(int8_t &opacity /* @out */) const = 0;

    /**
     * @brief Setter for WindowColor
     */
    virtual uint32_t SetWindowColor(const string &color) = 0;
    /**
     * @brief Getter for WindowColor
     */
    virtual uint32_t GetWindowColor(string &color /* @out */) const = 0;

    /**
     * @brief Setter for WindowOpacity
     */
    virtual uint32_t SetWindowOpacity(const int8_t opacity) = 0;
    /**
     * @brief Getter for WindowOpacity
     */
    virtual uint32_t GetWindowOpacity(int8_t &opacity /* @out */) const = 0;

    /* @} */
};


/*
    This is the COM-RPC interface for handling TextTrack sessions.
*/
/* @json 1.0.0 */
struct EXTERNAL ITextTrack : virtual public Core::IUnknown {
    enum {
        ID = ID_TEXT_TRACK
    };

    enum class DataType : uint8_t {
        PES = 0,
        TTML = 1,
        CC = 2,
        WEBVTT = 3
    };

    // Sessions
    /**
     * @brief Opens a new renderSession.
     * @details If a session is already running on the supplied the supplied displayHandle already has a running session, the sessionId for this session is
     * returned
     * @param displayHandle The displayHandle is an encoding of the wayland display name  optionally including the and window ID
     * @param sessionId On success the returned session id
     */
    virtual uint32_t OpenSession(const string &displayHandle, uint32_t &sessionId /* @out */) = 0;
    /**
     * @brief Closes a previously opened render session.
     * @details Any created windows and surfaces is destroyed
     * @param sessionId Is the session to close
     */
    virtual uint32_t CloseSession(const uint32_t sessionId) = 0;
    /**
     * @brief Resets a previously opened render session back to its opened state.
     * @details The text render display is cleared by the render session.
     * @param sessionId Is the session to reset
     */
    virtual uint32_t ResetSession(const uint32_t sessionId) = 0;
    /**
     * @brief Pauses a render session.
     * @details Any text rendered remains on screen and any text due to be rendered soon
     * is held until the render session is resumed.
     * @param sessionId Is the session
     */
    virtual uint32_t PauseSession(const uint32_t sessionId) = 0;
    /**
     * @brief Resumed a paused session
     * @param sessionId Is the session
     */
    virtual uint32_t ResumeSession(const uint32_t sessionId) = 0;
    /**
     * @brief Mute will hide rendering of Captions
     * @param sessionId Is the session
     */
    virtual uint32_t MuteSession(const uint32_t sessionId) = 0;
    /**
     * @brief UnMute will unhide the rendering of Captions.
     * @details A newly created session is muted and should be unmuted to me visible
     * @param sessionId Is the session
     */
    virtual uint32_t UnMuteSession(const uint32_t sessionId) = 0;

    /**
     * @brief Sends data of Closed Captions, Captions or Timed Text data to a render session.
     * @param sessionId Is the session
     * @param type Is the type of data
     * @param displayOffsetMs Is currently unused
     * @param data Is the data to display, properly formatted as per the expectations of the type used
     */
    virtual uint32_t SendSessionData(const uint32_t sessionId, const DataType type, const int32_t displayOffsetMs, const string &data) = 0;
    /**
     * @brief Sends the current timestamp from a media player to a render session.
     * @details The STC is used in some forms of text rendering to compare against the text data PTS to determine its presentation time.
     * @param sessionId Is the session
     * @param mediaTimestampMs Is a timestamp
     */
    virtual uint32_t SendSessionTimestamp(const uint32_t sessionId, const uint64_t mediaTimestampMs) = 0;

    /**
     * @brief  Applies a custom ClosedCaptionsStyle on a single session.
     * @details When a custom style is applied on a specific session we will not update the style for this session if the global style setting change.
     * The style setting will take effect immediately.
     * @param sessionId Is the session as returned in the ITextTrack interface.
     * @param style Contains the chosen styles
     * @json:omit
     */
    virtual uint32_t ApplyCustomClosedCaptionsStyleToSession(const uint32_t sessionId, const ITextTrackClosedCaptionsStyle::ClosedCaptionsStyle &style) = 0;

    /**
     * @brief Sets a static text in the display for preview purposes.
     * @details The session must be opened as usual and a type chosen. The text will only be shown if the type of session supports preview.
     * @param text Is the text to display
     * @returns Core::ERROR_OK if preview is shown
     * @returns Core::ERROR_NOT_SUPPORTED if preview is not supported
     */
    virtual uint32_t SetPreviewText(const uint32_t sessionId, const std::string &text) = 0;

    /*
     * The following methods initialize the mode of the TextTrack engine. All sessions are muted after
     * this call and it is the player's responsibility to unmute it.
     */

    /**
     * @brief Sets the render session into CC mode.
     * @details Selecting the specified CC service to decode and display in the specified render session.
     * This should be done before starting the injection of data.
     * Valid input for service is "CC[1-4]", "TEXT[1-4]", "SERVICE[1-64]"
     * @param sessionId Is the session
     * @param service Identifies the service to display e.g. "CC3"
     */
    virtual uint32_t SetSessionClosedCaptionsService(const uint32_t sessionId, const string &service) = 0;
    /**
     * @brief Set the render session into Teletext mode, providing the teletext caption page for presentation
     * @param sessionId Is the session
     * @param page The user selected teletext caption page 100-899
     */
    virtual uint32_t SetSessionTeletextSelection(const uint32_t sessionId, const uint16_t page) = 0;
    /**
     * @brief Set the render session into Dvb Subtitle mode, specifying the the page for presentation. (See ETSI EN 300 743)
     * @param sessionId Is the session
     * @param compositionPageId Is the one Id
     * @param ancillaryPageId Is the other Id
     */
    virtual uint32_t SetSessionDvbSubtitleSelection(const uint32_t sessionId, const uint16_t compositionPageId, const uint16_t ancillaryPageId) = 0;
    /**
     * @brief Set the render session into WebVTT mode
     * @param sessionId Is the session
     */
    virtual uint32_t SetSessionWebVTTSelection(const uint32_t sessionId) = 0;
    /**
     * @brief Set the render session into TTML mode
     * @param sessionId Is the session
     */
    virtual uint32_t SetSessionTTMLSelection(const uint32_t sessionId) = 0;
    /**
     * @brief Set the render session into SCTE mode
     * @param sessionId Is the session
     */
    virtual uint32_t SetSessionSCTESelection(const uint32_t sessionId) = 0;
};
} // namespace Exchange
} // namespace WPEFramework
